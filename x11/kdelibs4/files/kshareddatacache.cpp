/*
 * This file is part of the KDE project.
 * Copyright © 2010 Michael Pyne <mpyne@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License version 2 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "kshareddatacache.h"

#include <kdebug.h>
#include <kglobal.h>
#include <kstandarddirs.h>
#include <krandom.h>

#include <QtCore/QDateTime>
#include <QtCore/QSharedPointer>
#include <QtCore/QByteArray>
#include <QtCore/QFile>
#include <QtCore/QAtomicInt>
#include <QtCore/QList>
#include <QtCore/QMutex>
#include <QtCore/QMutexLocker>

#include <pthread.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Mac OS X, for all its POSIX compliance, does not support timeouts on its mutexes, which
// is kind of a disaster for cross-process support. So, disable support for shared memory
// and add a wrapper implementation.
#if !defined(_POSIX_TIMEOUTS) || !defined(_POSIX_THREADS) || (_POSIX_TIMEOUTS < 200112L) || (_POSIX_THREADS < 200112L)

#ifdef _POSIX_THREAD_PROCESS_SHARED
#undef _POSIX_THREAD_PROCESS_SHARED
#endif

#ifdef __GNUC__
#warning "No support for POSIX timeouts and POSIX threads -- shared memory will be ignored"
#endif

#endif

// BSD/Mac OS X compat
#if !defined(MAP_ANONYMOUS) && defined(MAP_ANON)
#define MAP_ANONYMOUS MAP_ANON
#endif

/**
 * This is the hash function used for our pixmap data to hopefully make the
 * hashing used to place the pixmaps as efficient as possible.
 *
 * The algorithm is in the public domain, by Glenn Fowler, Phong Vo, and Landon
 * Curt Noll, implemented by myself (mpyne).
 */
static quint32 fnvHash32(const QByteArray &buffer)
{
    static const quint32 FNVPrime = 16777619;
    static const quint32 FNVOffsetBasis = 2166136261;

    // uchar for correct arithmetic below
    const uchar *base = reinterpret_cast<const uchar *>(buffer.constData());
    quint32 result = FNVOffsetBasis;
    int count = buffer.length();

    while (count-- > 0) {
        result *= FNVPrime;
        result ^= *base;
        base++;
    }

    return result;
}

// Alignment concerns become a big deal when we're dealing with shared memory,
// since trying to access a structure sized at, say 8 bytes at an address that
// is not evenly divisible by 8 is a crash-inducing error on some
// architectures. The compiler would normally take care of this, but with
// shared memory the compiler will not necessarily know the alignment expected,
// so make sure we account for this ourselves. To do so we need a way to find
// out the expected alignment. Enter ALIGNOF...
#ifndef ALIGNOF
#if defined(Q_CC_GNU) || defined(Q_CC_SUN)
#define ALIGNOF(x) (__alignof__ (x)) // GCC provides what we want directly
#else

#include <stddef.h> // offsetof

template<class T>
struct __alignmentHack
{
    char firstEntry;
    T    obj;
    static const size_t size = offsetof(__alignmentHack, obj);
};
#define ALIGNOF(x) (__alignmentHack<x>::size)
#endif // Non gcc
#endif // ALIGNOF undefined

// Returns a pointer properly aligned to handle size alignment.
// size should be a power of 2. start is assumed to be the lowest
// permissible address, therefore the return value will be >= start.
template<class T>
T* alignTo(const void *start, uint size = ALIGNOF(T))
{
    quintptr mask = size - 1;

    // Cast to int-type to handle bit-twiddling
    quintptr basePointer = reinterpret_cast<quintptr>(start);

    // If (and only if) we are already aligned, adding mask into basePointer
    // will not increment any of the bits in ~mask and we get the right answer.
    basePointer = (basePointer + mask) & ~mask;

    return reinterpret_cast<T *>(basePointer);
}

/**
 * Returns a pointer to a const object of type T, assumed to be @p offset
 * *BYTES* greater than the base address. Note that in order to meet alignment
 * requirements for T, it is possible that the returned pointer points greater
 * than @p offset into @p base.
 */
template<class T>
const T *offsetAs(const void *const base, qint32 offset)
{
    const char *ptr = reinterpret_cast<const char*>(base);
    return alignTo<const T>(ptr + offset);
}

// Same as above, but for non-const objects
template<class T>
T *offsetAs(void *const base, qint32 offset)
{
    char *ptr = reinterpret_cast<char *>(base);
    return alignTo<T>(ptr + offset);
}

/**
 * @return the smallest integer greater than or equal to (@p a / @p b).
 * @param a Numerator, should be ≥ 0.
 * @param b Denominator, should be > 0.
 */
template<class T>
T intCeil(T a, T b)
{
    return (a + b - 1) / b;
}

typedef qint32 pageID;

// =========================================================================
// Description of the cache:
//
// The shared memory cache is designed to be handled as two separate objects,
// all contained in the same global memory segment. First off, there is the
// basic header data, consisting of the global header followed by the
// accounting data necessary to hold items (described in more detail
// momentarily). Following the accounting data is the start of the "page table"
// (essentially just as you'd see it in an Operating Systems text).
//
// The page table contains shared memory split into fixed-size pages, with a
// configurable page size. In the event that the data is too large to fit into
// a single logical page, it will need to occupy consecutive pages of memory.
//
// The accounting data that was referenced earlier is split into two:
//
// 1. index table, containing a fixed-size list of possible cache entries.
// Each index entry is of type IndexTableEntry (below), and holds the various
// accounting data and a pointer to the first page.
//
// 2. page table, which is used to speed up the process of searching for
// free pages of memory. There is one entry for every page in the page table,
// and it contains the index of the one entry in the index table actually
// holding the page (or <0 if the page is free).
//
// The entire segment looks like so:
// ╔════════╤═════════════╤════════════╦═══════╤═══════╤═══════╤═══════╤═══╗
// ║ Header │ Index Table │ Page Table ║ Pages │       │       │       │...║
// ╚════════╧═════════════╧════════════╩═══════╧═══════╧═══════╧═══════╧═══╝
// =========================================================================

// All elements of this struct must be "plain old data" (POD) types since it
// will be in shared memory.  In addition, no pointers!  To point to something
// you must use relative offsets since the pointer start addresses will be
// different in each process.
struct IndexTableEntry
{
            uint   fileNameHash;
            uint   totalItemSize; // in bytes
    mutable uint   useCount;
            time_t addTime;
    mutable time_t lastUsedTime;
            pageID firstPage;
};

// Page table entry
struct PageTableEntry
{
    // int so we can use values <0 for unassigned pages.
    qint32 index;
};

// Each individual page contains the cached data. The first page starts off with
// the utf8-encoded key, a null '\0', and then the data follows immediately
// from the next byte, possibly crossing consecutive page boundaries to hold
// all of the data.
// There is, however, no specific struct for a page, it is simply a location in
// memory.

// This is effectively the layout of the shared memory segment. The variables
// contained within form the header, data contained afterwards is pointed to
// by using special accessor functions.
struct SharedMemory
{
    enum {
        PIXMAP_CACHE_VERSION = 1,
        MINIMUM_CACHE_SIZE = 4096
    };

    // Note to those who follow me. You should not, under any circumstances, ever
    // re-arrange the following two fields, even if you change the version number
    // for later revisions of this code.
    QAtomicInt ready; ///< DO NOT INITIALIZE
    quint8     version;

    mutable pthread_mutex_t lockMutex;
    uint       cacheSize;
    uint       cacheAvail;
    QAtomicInt evictionPolicy;

    // pageSize and cacheSize determine the number of pages. The number of
    // pages determine the page table size and (indirectly) the index table
    // size.
    QAtomicInt pageSize;

    // This variable is added to reserve space for later cache timestamping
    // support. The idea is this variable will be updated when the cache is
    // written to, to allow clients to detect a changed cache quickly.
    QAtomicInt cacheTimestamp;

    /**
     * Converts the given average item size into an appropriate page size.
     */
    static unsigned equivalentPageSize(unsigned itemSize)
    {
        if (itemSize == 0) {
            return 4096; // Default average item size.
        }

        int log2OfSize = 0;
        while ((itemSize >>= 1) != 0) {
            log2OfSize++;
        }

        // Bound page size between 512 bytes and 256 KiB.
        log2OfSize = qBound(9, log2OfSize, 18);

        return (1 << log2OfSize);
    }

    // Returns pageSize in unsigned format.
    unsigned cachePageSize() const
    {
        return static_cast<unsigned>(pageSize);
    }

    /**
     * This is effectively the class ctor.  But since we're in shared memory,
     * there's a few rules:
     *
     * 1. To allow for some form of locking in the initial-setup case, we
     * use an atomic int, which will be initialized to 0 by mmap().  Then to
     * take the lock we atomically increment the 0 to 1.  If we end up calling
     * the QAtomicInt constructor we can mess that up, so we can't use a
     * constructor for this class either.
     * 2. Any member variable you add takes up space in shared memory as well,
     * so make sure you need it.
     */
    bool performInitialSetup(bool processShared, uint _cacheSize, uint _pageSize)
    {
        if (_cacheSize < MINIMUM_CACHE_SIZE) {
            kError(264) << "Internal error: Attempted to create a cache sized < "
                        << MINIMUM_CACHE_SIZE;
            return false;
        }

        if (_pageSize == 0) {
            kError(264) << "Internal error: Attempted to create a cache with 0-sized pages.";
            return false;
        }

        if (processShared) {
            // Perform initialization.  We effectively hold a mini-lock right
            // now as long as all clients cooperate...
            pthread_mutexattr_t mutexAttr;

            // Initialize attributes, enable process-shared primitives, and setup
            // the mutex.
            if (pthread_mutexattr_init(&mutexAttr) == 0) {
                if (
#ifdef _POSIX_THREAD_PROCESS_SHARED
                    pthread_mutexattr_setpshared(&mutexAttr, PTHREAD_PROCESS_SHARED) != 0 ||
#endif
                    pthread_mutex_init(&lockMutex, &mutexAttr) != 0)
                {
                    pthread_mutexattr_destroy(&mutexAttr);
                    return false; // No process sharing
                }

                pthread_mutexattr_destroy(&mutexAttr);
            }
            else {
                return false; // No mutex attrs
            }
        }
        else {
            // Only thread-shared
            if (pthread_mutex_init(&lockMutex, 0) != 0) {
                return false;
            }
        }

        // These must be updated to make some of our auxiliary functions
        // work right since their values will be based on the cache size.
        cacheSize = _cacheSize;
        pageSize = _pageSize;
        version = PIXMAP_CACHE_VERSION;
        cacheTimestamp = static_cast<unsigned>(::time(0));

        clearInternalTables();

        // Unlock the mini-lock, and introduce a total memory barrier to make
        // sure all changes have propagated even without a mutex.
        ready.ref();

        return true;
    }

    void clearInternalTables()
    {
        // Assumes we're already locked somehow.
        cacheAvail = pageTableSize();

        // Setup page tables to point nowhere
        PageTableEntry *table = pageTable();
        for (uint i = 0; i < pageTableSize(); ++i) {
            table[i].index = -1;
        }

        // Setup index tables to be accurate.
        IndexTableEntry *indices = indexTable();
        for (uint i = 0; i < indexTableSize(); ++i) {
            indices[i].firstPage = -1;
        }
    }

    const IndexTableEntry *indexTable() const
    {
        // Index Table goes immediately after this struct, at the first byte
        // where alignment constraints are met (accounted for by offsetAs).
        return offsetAs<IndexTableEntry>(this, sizeof(*this));
    }

    const PageTableEntry *pageTable() const
    {
        const IndexTableEntry *base = indexTable();
        base += indexTableSize();

        // Let's call wherever we end up the start of the page table...
        return alignTo<PageTableEntry>(base);
    }

    const void *cachePages() const
    {
        const PageTableEntry *tableStart = pageTable();
        tableStart += pageTableSize();

        // Let's call wherever we end up the start of the data...
        return alignTo<void>(tableStart, cachePageSize());
    }

    const void *page(pageID at) const
    {
        if (static_cast<int>(at) >= static_cast<int>(pageTableSize())) {
            return 0;
        }

        // We must manually calculate this one since pageSize varies.
        const char *pageStart = reinterpret_cast<const char *>(cachePages());
        pageStart += (at * cachePageSize());

        return reinterpret_cast<const void *>(pageStart);
    }

    // The following are non-const versions of some of the methods defined
    // above.  They use const_cast<> because I feel that is better than
    // duplicating the code.  I suppose template member functions (?)
    // may work, may investigate later.
    IndexTableEntry *indexTable()
    {
        const SharedMemory *that = const_cast<const SharedMemory*>(this);
        return const_cast<IndexTableEntry *>(that->indexTable());
    }

    PageTableEntry *pageTable()
    {
        const SharedMemory *that = const_cast<const SharedMemory*>(this);
        return const_cast<PageTableEntry *>(that->pageTable());
    }

    void *cachePages()
    {
        const SharedMemory *that = const_cast<const SharedMemory*>(this);
        return const_cast<void *>(that->cachePages());
    }

    void *page(pageID at)
    {
        const SharedMemory *that = const_cast<const SharedMemory*>(this);
        return const_cast<void *>(that->page(at));
    }

    uint pageTableSize() const
    {
        return cacheSize / cachePageSize();
    }

    uint indexTableSize() const
    {
        // Assume 2 pages on average are needed -> the number of entries
        // would be half of the number of pages.
        return pageTableSize() / 2;
    }

    /**
     * @return the index of the first page, for the set of contiguous
     * pages that can hold @p pagesNeeded PAGES.
     */
    pageID findEmptyPages(uint pagesNeeded) const
    {
        // Loop through the page table, find the first empty page, and just
        // makes sure that there are enough free pages.
        const PageTableEntry *table = pageTable();
        uint contiguousPagesFound = 0;
        pageID base = 0;
        for (pageID i = 0; i < static_cast<int>(pageTableSize() - pagesNeeded + 1); ++i) {
            if (table[i].index < 0) {
                if (contiguousPagesFound == 0) {
                    base = i;
                }
                contiguousPagesFound++;
            }
            else {
                contiguousPagesFound = 0;
            }

            if (contiguousPagesFound == pagesNeeded) {
                return base;
            }
        }

        return pageTableSize();
    }

    // left < right?
    static bool lruCompare(const IndexTableEntry &l, const IndexTableEntry &r)
    {
        // Ensure invalid entries migrate to the end
        if (l.firstPage == -1 && r.firstPage >= 0) {
            return false;
        }
        if (l.firstPage >= 0 && r.firstPage == -1) {
            return true;
        }

        // Most recently used will have the highest absolute time =>
        // least recently used (lowest) should go first => use left < right
        return l.lastUsedTime < r.lastUsedTime;
    }

    // left < right?
    static bool seldomUsedCompare(const IndexTableEntry &l, const IndexTableEntry &r)
    {
        // Ensure invalid entries migrate to the end
        if (l.firstPage == -1 && r.firstPage >= 0) {
            return false;
        }
        if (l.firstPage >= 0 && r.firstPage == -1) {
            return true;
        }

        // Put lowest use count at start by using left < right
        return l.useCount < r.useCount;
    }

    // left < right?
    static bool ageCompare(const IndexTableEntry &l, const IndexTableEntry &r)
    {
        // Ensure invalid entries migrate to the end
        if (l.firstPage == -1 && r.firstPage >= 0) {
            return false;
        }
        if (l.firstPage >= 0 && r.firstPage == -1) {
            return true;
        }

        // Oldest entries die first -- they have the lowest absolute add time,
        // so just like the others use left < right
        return l.addTime < r.addTime;
    }

    void defragment()
    {
        if (cacheAvail * cachePageSize() == cacheSize) {
            return; // That was easy
        }

        kDebug(264) << "Defragmenting the shared cache";

        // Just do a linear scan, and anytime there is free space, swap it
        // with the pages to its right. In order to meet the precondition
        // we need to skip any used pages first.

        pageID currentPage = 0;
        pageID idLimit = static_cast<pageID>(pageTableSize());
        PageTableEntry *pages = pageTable();

        // Skip used pages
        while (currentPage < idLimit && pages[currentPage].index >= 0) {
            ++currentPage;
        }

        pageID freeSpot = currentPage;

        // Main loop, starting from a free page, skip to the used pages and
        // move them back.
        while (currentPage < idLimit) {
            // Find the next used page
            while (currentPage < idLimit && pages[currentPage].index < 0) {
                ++currentPage;
            }

            if (currentPage >= idLimit) {
                break;
            }

            // Found an entry, move it.
            qint32 affectedIndex = pages[currentPage].index;
            Q_ASSERT(affectedIndex >= 0);
            Q_ASSERT(indexTable()[affectedIndex].firstPage == currentPage);

            indexTable()[affectedIndex].firstPage = freeSpot;

            // Moving one page at a time guarantees we can use memcpy safely
            // (in other words, the source and destination will not overlap).
            while (currentPage < idLimit && pages[currentPage].index >= 0) {
                ::memcpy(page(freeSpot), page(currentPage), cachePageSize());
                pages[freeSpot].index = affectedIndex;
                pages[currentPage].index = -1;
                ++currentPage;
                ++freeSpot;

                // If we've just moved the very last page and it happened to
                // be at the very end of the cache then we're done.
                if (currentPage >= idLimit) {
                    break;
                }

                // We're moving consecutive used pages whether they belong to
                // our affected entry or not, so detect if we've started moving
                // the data for a different entry and adjust if necessary.
                if (affectedIndex != pages[currentPage].index) {
                    indexTable()[pages[currentPage].index].firstPage = freeSpot;
                }
                affectedIndex = pages[currentPage].index;
            }

            // At this point currentPage is on a page that is unused, and the
            // cycle repeats. However, currentPage is not the first unused
            // page, freeSpot is, so leave it alone.
        }
    }

    qint32 findNamedEntry(const QByteArray &key) const
    {
        uint keyHash = fnvHash32(key);
        uint position = keyHash % indexTableSize();
        int probeNumber = 1; // See insert() for description

        while (indexTable()[position].fileNameHash != keyHash &&
              indexTable()[position].useCount > 0 &&
              probeNumber < 6)
        {
            position = (keyHash + (probeNumber + probeNumber * probeNumber) / 2)
                       % indexTableSize();
            probeNumber++;
        }

        if (indexTable()[position].fileNameHash == keyHash) {
            pageID firstPage = indexTable()[position].firstPage;
            if (firstPage < 0) {
                return -1;
            }
            const void *resultPage = page(firstPage);
            const char *utf8FileName = reinterpret_cast<const char *>(resultPage);

            if (qstrcmp(utf8FileName, key.constData()) == 0) {
                return position;
            }
        }

        return -1; // Not found, or a different one found.
    }

    // Function to use with QSharedPointer in removeUsedPages below...
    static void deleteTable(IndexTableEntry *table) {
        delete [] table;
    }

    uint removeUsedPages(uint numberNeeded)
    {
        if (numberNeeded > pageTableSize()) {
            kError(264) << "Internal error: Requested more space than exists in the cache.";
            kError(264) << numberNeeded << "requested, " << pageTableSize() << "is the total possible.";
            return pageTableSize();
        }

        // To avoid calling findEmptyPages() all the time we will figure out
        // the minimum number of pages required to fulfill the request if the
        // page table were perfectly defragmented, and remove at least that
        // amount first. If the cache free space is large enough we will
        // defragment first instead since it's likely we're highly fragmented.
        uint freedPagesRequired = 0;
        if (numberNeeded > cacheAvail) {
            freedPagesRequired = numberNeeded - cacheAvail;
        }

        kDebug(264) << "Removing old entries to free up" << numberNeeded << "pages,"
                    << cacheAvail << "are already theoretically available.";

        if (cacheAvail > 3 * numberNeeded) {
            defragment();
            uint result = findEmptyPages(numberNeeded);

            if (result < pageTableSize()) {
                return result;
            }
            else {
                kError(264) << "Just defragmented a locked cache, but still there"
                            << "isn't enough room for the current request.";
            }
        }

        // At this point we know we'll have to free some space up, so sort our
        // list of entries by whatever the current criteria are and start
        // killing expired entries.
        QSharedPointer<IndexTableEntry> tablePtr(new IndexTableEntry[indexTableSize()], deleteTable);

        // We use tablePtr to ensure the data is destroyed, but do the access
        // via a helper pointer to allow for array ops.
        IndexTableEntry *table = tablePtr.data();

        ::memcpy(table, indexTable(), sizeof(IndexTableEntry) * indexTableSize());

        // Our entry ID is simply its index into the
        // index table, which qSort will rearrange all willy-nilly, so first
        // we'll save the *real* entry ID into firstPage (which is useless in
        // our copy of the index table. On the other hand if the entry is not
        // used then we note that with -1.
        for (uint i = 0; i < indexTableSize(); ++i) {
            table[i].firstPage = table[i].useCount > 0 ? static_cast<pageID>(i)
                                                       : -1;
        }

        // Declare the comparison function that we'll use to pass to qSort,
        // based on our cache eviction policy.
        bool (*compareFunction)(const IndexTableEntry &, const IndexTableEntry &);
        switch((int) evictionPolicy) {
        case (int) KSharedDataCache::EvictLeastOftenUsed:
        case (int) KSharedDataCache::NoEvictionPreference:
        default:
            compareFunction = seldomUsedCompare;
        break;

        case (int) KSharedDataCache::EvictLeastRecentlyUsed:
            compareFunction = lruCompare;
        break;

        case (int) KSharedDataCache::EvictOldest:
            compareFunction = ageCompare;
        break;
        }

        qSort(table, table + indexTableSize(), compareFunction);

        // Least recently used entries will be in the front.
        // Start killing until we have room.

        // Note on removeEntry: It expects an index into the index table,
        // but our sorted list is all jumbled. But we stored the real index
        // in the firstPage member.
        // Remove entries until we've removed at least the required number
        // of pages.
        uint i = 0;
        while (i < indexTableSize() && numberNeeded > cacheAvail) {
            int curIndex = table[i++].firstPage;

            // Removed everything, still no luck. At *this* point,
            // pagesRemoved < numberNeeded or in other words we can't fulfill
            // the request even if we defragment. This is really a logic error.
            if (curIndex < 0) {
                kError(264) << "Unable to remove enough used pages to allocate"
                              << numberNeeded << "pages. In theory the cache is empty, weird.";
                return pageTableSize();
            }

            kDebug(264) << "Removing entry of" << indexTable()[curIndex].totalItemSize
                        << "size";
            removeEntry(curIndex);
        }

        // At this point let's see if we have freed up enough data by
        // defragmenting first and seeing if we can find that free space.
        defragment();

        pageID result = pageTableSize();
        while (i < indexTableSize() &&
              (result = findEmptyPages(numberNeeded)) >= static_cast<int>(pageTableSize()))
        {
            int curIndex = table[i++].firstPage;

            if (curIndex < 0) {
                // One last shot.
                defragment();
                return findEmptyPages(numberNeeded);
            }

            removeEntry(curIndex);
        }

        // Whew.
        return result;
    }

    // Returns the total size required for a given cache size.
    static uint totalSize(uint cacheSize, uint effectivePageSize)
    {
        uint numberPages = intCeil(cacheSize, effectivePageSize);
        uint indexTableSize = numberPages / 2;

        // Knowing the number of pages, we can determine what addresses we'd be
        // using (properly aligned), and from there determine how much memory
        // we'd use.
        IndexTableEntry *indexTableStart =
                    offsetAs<IndexTableEntry>(static_cast<void*>(0), sizeof (SharedMemory));

        indexTableStart += indexTableSize;

        PageTableEntry *pageTableStart = reinterpret_cast<PageTableEntry *>(indexTableStart);
        pageTableStart = alignTo<PageTableEntry>(pageTableStart);
        pageTableStart += numberPages;

        // The weird part, we must manually adjust the pointer based on the page size.
        char *cacheStart = reinterpret_cast<char *>(pageTableStart);
        cacheStart += (numberPages * effectivePageSize);

        // ALIGNOF gives pointer alignment
        cacheStart = alignTo<char>(cacheStart, ALIGNOF(void*));

        // We've traversed the header, index, page table, and cache.
        // Wherever we're at now is the size of the enchilada.
        return static_cast<uint>(reinterpret_cast<quintptr>(cacheStart));
    }

    uint fileNameHash(const QByteArray &utf8FileName) const
    {
        return fnvHash32(utf8FileName) % indexTableSize();
    }

    bool lock() const
    {
#ifdef _POSIX_THREAD_PROCESS_SHARED
        struct timespec timeout;

        // Long timeout, but if we fail to meet this timeout it's probably a cache
        // corruption (and if we take 8 seconds then it should be much much quicker
        // the next time anyways since we'd be paged back in from disk)
        timeout.tv_sec = 10 + ::time(NULL); // Absolute time, so 10 seconds from now
        timeout.tv_nsec = 0;

        return pthread_mutex_timedlock(&lockMutex, &timeout) >= 0;
#else
        // Some POSIX platforms don't have full support for pthreads. On these typically
        // there will be no timedlock, so just don't bother and accept hangs on weird
        // platforms.
        return pthread_mutex_lock(&lockMutex) == 0;
#endif
    }

    void unlock() const
    {
        pthread_mutex_unlock(&lockMutex);
    }

    void clear()
    {
        lock();
        clearInternalTables();
        unlock();
    }

    void removeEntry(uint index);
};

// The per-instance private data, such as map size, whether
// attached or not, pointer to shared memory, etc.
class KSharedDataCache::Private
{
    public:
    Private(const QString &name,
            unsigned defaultCacheSize,
            unsigned expectedItemSize
           )
        : shm(0)
        , m_cacheName(name)
        , m_attached(false)
        , m_mapSize(0)
        , m_defaultCacheSize(defaultCacheSize)
        , m_expectedItemSize(expectedItemSize)
    {
        mapSharedMemory();
    }

    // This function does a lot of the important work, attempting to connect to shared
    // memory, a private anonymous mapping if that fails, and failing that, nothing (but
    // the cache remains "valid", we just don't actually do anything).
    void mapSharedMemory()
    {
        // 0-sized caches are fairly useless.
        unsigned cacheSize = qMax(m_defaultCacheSize, uint(SharedMemory::MINIMUM_CACHE_SIZE));
        unsigned pageSize = SharedMemory::equivalentPageSize(m_expectedItemSize);

        // Ensure that the cache is sized such that there is a minimum number of
        // pages available. (i.e. a cache consisting of only 1 page is fairly
        // useless and probably crash-prone).
        cacheSize = qMax(pageSize * 256, cacheSize);

        // The m_cacheName is used to find the file to store the cache in.
        QString cacheName = KGlobal::dirs()->locateLocal("cache", m_cacheName + QLatin1String(".kcache"));
        QFile file(cacheName);

        kDebug(264) << "Opening cache" << cacheName << "page size is" << pageSize;

        // The basic idea is to open the file that we want to map into shared
        // memory, and then actually establish the mapping. Once we have mapped the
        // file into shared memory we can close the file handle, the mapping will
        // still be maintained (unless the file is resized to be shorter than
        // expected, which we don't handle yet :-( )

        // size accounts for the overhead over the desired cacheSize
        uint size = SharedMemory::totalSize(cacheSize, pageSize);
        void *mapAddress = MAP_FAILED;

        if (size < cacheSize) {
            kError(264) << "Asked for a cache size less than requested size somehow -- Logic Error :(";
            return;
        }

        bool systemSupportsProcessSharing = false;

// Compile time check ensures the required constants from the .h are available to be
// queried at all.
#ifdef _POSIX_THREAD_PROCESS_SHARED
        systemSupportsProcessSharing = ::sysconf(_SC_THREAD_PROCESS_SHARED) > 0;
#endif

        // We establish the shared memory mapping here, only if we will have appropriate
        // mutex support (systemSupportsProcessSharing), then we:
        // Open the file and resize to some sane value if the file is too small.
        if (systemSupportsProcessSharing &&
            file.open(QIODevice::ReadWrite) &&
           (file.size() >= size || file.resize(size)))
        {
            // Use mmap directly instead of QFile::map since the QFile (and its
            // shared mapping) will disappear unless we hang onto the QFile for no
            // reason (see the note below, we don't care about the file per se...)
            mapAddress = ::mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, file.handle(), 0);

            // So... it is possible that someone else has mapped this cache already
            // with a larger size. If that's the case we need to at least match
            // the size to be able to access every entry, so fixup the mapping.
            if (mapAddress != MAP_FAILED) {
                SharedMemory *mapped = reinterpret_cast<SharedMemory *>(mapAddress);

                // First make sure that the version of the cache on disk is
                // valid.  We also need to check that version != 0 to
                // disambiguate against an uninitialized cache.
                if (mapped->version != SharedMemory::PIXMAP_CACHE_VERSION &&
                    mapped->version > 0)
                {
                    kWarning(264) << "Deleting wrong version of cache" << cacheName;

                    // CAUTION: Potentially recursive since the recovery
                    // involves calling this function again.
                    m_attached = true;
                    m_mapSize = size;
                    shm = mapped;
                    recoverCorruptedCache();
                    return;
                }
                else if (mapped->cacheSize > cacheSize) {
                    // This order is very important. We must save the cache size
                    // before we remove the mapping, but unmap before overwriting
                    // the previous mapping size...
                    cacheSize = mapped->cacheSize;
                    unsigned actualPageSize = mapped->cachePageSize();
                    ::munmap(mapAddress, size);
                    size = SharedMemory::totalSize(cacheSize, actualPageSize);
                    mapAddress = ::mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, file.handle(), 0);
                }
            }
        }

        // We could be here without the mapping established if:
        // 1) Process-shared synchronization is not supported, either at compile or run time,
        // 2) Unable to open the required file.
        // 3) Unable to resize the file to be large enough.
        // 4) Establishing the mapping failed.
        // 5) The mapping succeeded, but the size was wrong and we were unable to map when
        //    we tried again.
        // 6) The incorrect version of the cache was detected.
        // In any of these cases, attempt to fallback to the
        // better-supported anonymous private page style of mmap. This memory won't
        // be shared, but our code will still work the same.
        // NOTE: We never use the on-disk representation independently of the
        // shared memory. If we don't get shared memory the disk info is ignored,
        // if we do get shared memory we never look at disk again.
        bool usingSharedMapping = true;
        if (mapAddress == MAP_FAILED) {
            kWarning(264) << "Failed to establish shared memory mapping, will fallback"
                          << "to private memory -- memory usage will increase";

            mapAddress = ::mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
            usingSharedMapping = false;
        }

        // Well now we're really hosed. We can still work, but we can't even cache
        // data.
        if (mapAddress == MAP_FAILED) {
            kError(264) << "Unable to allocate shared memory segment for shared data cache"
                        << cacheName << "of size" << cacheSize;
            return;
        }

        kDebug(264) << "Attached to cache, determining if it must be initialized";

        m_mapSize = size;

        // We never actually construct shm, but we assign it the same address as the
        // shared memory we just mapped, so effectively shm is now a SharedMemory that
        // happens to be located at mapAddress.
        shm = reinterpret_cast<SharedMemory *>(mapAddress);

        // If we were first to create this memory map, all data will be 0.
        // Therefore if ready == 0 we're not initialized.  A fully initialized
        // header will have ready == 2.  Why?
        // Because 0 means "safe to initialize"
        //         1 means "in progress of initing"
        //         2 means "ready"
        uint usecSleepTime = 8; // Start by sleeping for 8 microseconds
        while (shm->ready != 2) {
            if (usecSleepTime >= (1 << 21)) {
                // Didn't acquire within ~8 seconds?  Assume an issue exists
                kError(264) << "Unable to acquire shared lock, is the cache corrupt?";

                ::munmap(mapAddress, size);
                file.remove(); // Unlink the cache in case it's corrupt.
                return; // Fallback to QCache (later)
            }

            if (shm->ready.testAndSetAcquire(0, 1)) {
                if (!shm->performInitialSetup(usingSharedMapping, cacheSize, pageSize)) {
                    kError(264) << "Unable to perform initial setup, this system probably "
                                   "does not really support process-shared pthreads, even "
                                   "though it claims otherwise.";
                    ::munmap(mapAddress, size);
                    file.remove();
                    return;
                }
            }
            else {
                usleep(usecSleepTime); // spin

                // Exponential fallback as in Ethernet and similar collision resolution methods
                usecSleepTime *= 2;
            }
        }

        // We are "attached" if we have a valid memory mapping, whether it is
        // shared or private.
        kDebug(264) << "Cache fully initialized -- attached to memory mapping";
        kDebug(264) << shm->cacheAvail * shm->cachePageSize() << "bytes available out of"
                    << shm->cacheSize;
        m_attached = true;
    }

    // Called whenever the cache is apparently corrupt (for instance, a timeout trying to
    // lock the cache). In this situation it is safer just to destroy it all and try again.
    void recoverCorruptedCache()
    {
        KSharedDataCache::deleteCache(m_cacheName);
        if (m_attached) {
            ::munmap(shm, m_mapSize);
            m_attached = false;
            shm = 0;
            m_mapSize = 0;
        }

        // Do this even if we weren't previously cached -- it might work now.
        mapSharedMemory();
    }

    class CacheLocker
    {
        mutable Private * d;

        bool cautiousLock()
        {
            int lockCount = 0;

            // Locking can fail due to a timeout. If it happens too often even though
            // we're taking corrective action assume there's some disastrous problem
            // and give up.
            while (!d->shm->lock()) {
                d->recoverCorruptedCache();

                if (!d->m_attached) {
                    kWarning(264) << "Lost the connection to shared memory for cache"
                                  << d->m_cacheName;
                    return false;
                }

                if (lockCount++ > 4) {
                    kError(264) << "There is a very serious problem with the KDE data cache"
                                << d->m_cacheName << "giving up trying to access cache.";
                    ::munmap(d->shm, d->m_mapSize);
                    d->shm = 0;
                    d->m_attached = false;
                    return false;
                }
            }

            return true;
        }

        public:
        CacheLocker(const Private *_d) : d(const_cast<Private *>(_d))
        {
            if (d->m_attached) {
                // A separate mutex for the shm lock? What gives?
                // The reason is that we have to check to see if the cache
                // was made bigger by a different process. If so, we need to
                // re-map the cache to accomodate that. In that event, we will
                // need to un-map the cache first.
                //
                // Now imagine what happens if two threads in this same process
                // tried to do this concurrently. Since we wouldn't be attached
                // to shm we couldn't use d->shm->lock to be safe during that
                // critical section (in between unlock and the subsequent
                // lock), so one thread could set shm = 0 after unmapping and
                // cause the other thread to crash. So we need a separate
                // single-process/multiple-thread lock to be super-safe.
                QMutexLocker d_locker(&d->m_threadLock);

                if (!cautiousLock()) {
                    return;
                }

                uint testSize = SharedMemory::totalSize(d->shm->cacheSize, d->shm->cachePageSize());

                // A while loop? Indeed, think what happens if this happens
                // twice -- hard to debug race conditions.
                while (testSize > d->m_mapSize) {
                    kDebug(264) << "Someone enlarged the cache on us,"
                                << "attempting to match new configuration.";

                    // Linux supports mremap, but it's not portable. So,
                    // drop the map and (try to) re-establish.
                    d->shm->unlock();

                    ::munmap(d->shm, d->m_mapSize);
                    d->m_attached = false;
                    d->m_mapSize = 0;
                    d->shm = 0;

                    QFile f(d->m_cacheName);
                    if (!f.open(QFile::ReadWrite)) {
                        kError(264) << "Unable to re-open cache, unfortunately"
                                    << "the connection had to be dropped for"
                                    << "crash safety -- things will be much"
                                    << "slower now.";
                        return;
                    }

                    void *newMap = ::mmap(0, testSize, PROT_READ | PROT_WRITE,
                                          MAP_SHARED, f.handle(), 0);
                    if (newMap == MAP_FAILED) {
                        kError(264) << "Unopen to re-map the cache into memory"
                                    << "things will be much slower now";
                        return;
                    }

                    d->shm = reinterpret_cast<SharedMemory *>(newMap);
                    d->m_attached = true;
                    d->m_mapSize = testSize;

                    if (!cautiousLock()) {
                        return;
                    }

                    testSize = SharedMemory::totalSize(d->shm->cacheSize, d->shm->cachePageSize());
                }
            }
        }

        ~CacheLocker()
        {
            if (d->m_attached) {
                d->shm->unlock();
            }
        }

        bool failed() const
        {
            return d->shm == 0;
        }
    };

    SharedMemory *shm;
    QString m_cacheName;
    QMutex m_threadLock;
    bool m_attached;
    uint m_mapSize;
    uint m_defaultCacheSize;
    uint m_expectedItemSize;
};

// Must be called while the lock is already held!
void SharedMemory::removeEntry(uint index)
{
    Q_ASSERT(index < indexTableSize());
    Q_ASSERT(cacheAvail <= pageTableSize());

    PageTableEntry *pageTableEntries = pageTable();
    IndexTableEntry *entriesIndex = indexTable();

    // Update page table first
    pageID firstPage = entriesIndex[index].firstPage;
    if (firstPage < 0 || firstPage >= pageTableSize()) {
        kError(264) << "Removing" << index << "which is already marked as empty!";
        return;
    }

    if (index != static_cast<uint>(pageTableEntries[firstPage].index)) {
        kError(264) << "Removing" << index << "will not work as it is assigned"
                    << "to page" << firstPage << "which is itself assigned to"
                    << "entry" << pageTableEntries[firstPage].index << "instead!";
        return;
    }

    uint entriesToRemove = intCeil(entriesIndex[index].totalItemSize, cachePageSize());
    uint savedCacheSize = cacheAvail;
    for (uint i = firstPage; i < pageTableSize() &&
        (uint) pageTableEntries[i].index == index; ++i)
    {
        pageTableEntries[i].index = -1;
        cacheAvail++;
    }

    if ((cacheAvail - savedCacheSize) != entriesToRemove) {
        kError(264) << "We somehow did not remove" << entriesToRemove
                    << "when removing entry" << index << ", instead we removed"
                    << (cacheAvail - savedCacheSize);
    }

    // For debugging
#ifdef NDEBUG
    QByteArray str((const char *)page(firstPage));
    str.prepend(" REMOVED: ");
    str.prepend(QByteArray::number(index));
    str.prepend("ENTRY ");

    ::memcpy(page(firstPage), str.constData(), str.size() + 1);
#endif

    // Update the index
    entriesIndex[index].fileNameHash = 0;
    entriesIndex[index].totalItemSize = 0;
    entriesIndex[index].useCount = 0;
    entriesIndex[index].lastUsedTime = 0;
    entriesIndex[index].addTime = 0;
    entriesIndex[index].firstPage = -1;
}

KSharedDataCache::KSharedDataCache(const QString &cacheName,
                                   unsigned defaultCacheSize,
                                   unsigned expectedItemSize)
  : d(new Private(cacheName, defaultCacheSize, expectedItemSize))
{
}

KSharedDataCache::~KSharedDataCache()
{
    // Note that there is no other actions required to separate from the
    // shared memory segment, simply unmapping is enough. This makes things
    // *much* easier so I'd recommend maintaining this ideal.
    if (d->m_attached) {
        ::munmap(d->shm, d->m_mapSize);
    }

    // Do not delete d->shm, it was never constructed, it's just an alias.
    d->shm = 0;

    delete d;
}

bool KSharedDataCache::insert(const QString &key, const QByteArray &data)
{
    Private::CacheLocker lock(d);
    if (lock.failed()) {
        return false;
    }

    QByteArray encodedKey = key.toUtf8();
    uint keyHash = fnvHash32(encodedKey);
    uint position = keyHash % d->shm->indexTableSize();

    // See if we're overwriting an existing entry.
    IndexTableEntry *indices = d->shm->indexTable();

    // In order to avoid the issue of a very long-lived cache having items
    // with a use count of 1 near-permanently, we attempt to artifically
    // reduce the use count of long-lived items when there is high load on
    // the cache. We do this randomly, with a weighting that makes the event
    // impossible if load < 0.5, and guaranteed if load >= 0.96.
    static double startCullPoint = 0.5l;
    static double mustCullPoint = 0.96l;

    // cacheAvail is in pages, cacheSize is in bytes.
    double loadFactor = (1.0l * d->shm->cacheAvail * d->shm->cachePageSize()
                              / d->shm->cacheSize);
    bool cullCollisions = false;

    if (KDE_ISUNLIKELY(loadFactor >= mustCullPoint)) {
        cullCollisions = true;
    }
    else {
        int tripWireValue = RAND_MAX * (loadFactor - startCullPoint) / (mustCullPoint - startCullPoint);
        if (KRandom::random() >= tripWireValue) {
            cullCollisions = true;
        }
    }

    // In case of collisions, use quadratic chaining to attempt to find an
    // empty slot. The equation we use is
    // position = (hash + (i + i*i) / 2) % size, where i is the probe number.
    int probeNumber = 1;
    while (indices[position].useCount > 0 && probeNumber < 6) {
        // If we are "culling" old entries, see if this one is old and if so
        // reduce its use count. If it reduces to zero then eliminate it and
        // use its old spot.

        if (cullCollisions && (indices[position].lastUsedTime - ::time(0)) > 60) {
            indices[position].useCount >>= 1;
            if (indices[position].useCount == 0) {
                kDebug(264) << "Overwriting existing old cached entry due to collision.";
                d->shm->removeEntry(position); // Remove it first

                break;
            }
        }

        position = (keyHash + (probeNumber + probeNumber * probeNumber) / 2)
                   % d->shm->indexTableSize();
        probeNumber++;
    }

    if (indices[position].useCount > 0 && indices[position].firstPage >= 0) {
        kDebug(264) << "Overwriting existing cached entry due to collision.";
        d->shm->removeEntry(position); // Remove it first
    }

    // Data will be stored as fileNamefoo\0PNGimagedata.....
    // So total size required is the length of the encoded file name + 1
    // for the trailing null, and then the length of the image data.
    uint fileNameLength = 1 + encodedKey.length();
    uint requiredSize = fileNameLength + data.size();
    uint pagesNeeded = intCeil(requiredSize, d->shm->cachePageSize());
    uint firstPage = (uint) -1;

    if (pagesNeeded >= d->shm->pageTableSize()) {
        kWarning(264) << key << "is too large to be cached.";
        return false;
    }

    // If the cache has no room, or the fragmentation is too great to find
    // the required number of consecutive free pages, take action.
    if (pagesNeeded > d->shm->cacheAvail ||
       (firstPage = d->shm->findEmptyPages(pagesNeeded)) >= d->shm->pageTableSize())
    {
        // If we have enough free space just defragment
        uint freePagesDesired = 3 * qMax(1u, pagesNeeded / 2);

        if (d->shm->cacheAvail > freePagesDesired) {
            // TODO: How the hell long does this actually take on real
            // caches?
            d->shm->defragment();
            firstPage = d->shm->findEmptyPages(pagesNeeded);
        }
        else {
            // If we already have free pages we don't want to remove a ton
            // extra. However we can't rely on the return value of
            // removeUsedPages giving us a good location since we're not
            // passing in the actual number of pages that we need.
            d->shm->removeUsedPages(qMin(2 * freePagesDesired, d->shm->pageTableSize())
                                    - d->shm->cacheAvail);
            firstPage = d->shm->findEmptyPages(pagesNeeded);
        }

        if (firstPage >= d->shm->pageTableSize() ||
           d->shm->cacheAvail < pagesNeeded)
        {
            kError(264) << "Unable to free up memory for" << key;
            return false;
        }
    }

    // Update page table
    PageTableEntry *table = d->shm->pageTable();
    for (uint i = 0; i < pagesNeeded; ++i) {
        table[firstPage + i].index = position;
    }

    // Update index
    indices[position].fileNameHash = keyHash;
    indices[position].totalItemSize = requiredSize;
    indices[position].useCount = 1;
    indices[position].addTime = ::time(0);
    indices[position].lastUsedTime = indices[position].addTime;
    indices[position].firstPage = firstPage;

    // Update cache
    d->shm->cacheAvail -= pagesNeeded;

    // Actually move the data in place
    void *dataPage = d->shm->page(firstPage);

    // Cast for byte-sized pointer arithmetic
    uchar *startOfPageData = reinterpret_cast<uchar *>(dataPage);
    ::memcpy(startOfPageData, encodedKey.constData(), fileNameLength);
    ::memcpy(startOfPageData + fileNameLength, data.constData(), data.size());

    return true;
}

bool KSharedDataCache::find(const QString &key, QByteArray *destination) const
{
    if (!d->m_attached) {
        return false;
    }

    Private::CacheLocker lock(d);
    if (lock.failed()) {
        return false;
    }

    // Search in the index for our data, hashed by key;
    QByteArray encodedKey = key.toUtf8();
    qint32 entry = d->shm->findNamedEntry(encodedKey);

    if (entry >= 0) {
        const IndexTableEntry *header = &d->shm->indexTable()[entry];
        const void *resultPage = d->shm->page(header->firstPage);

        header->useCount++;
        header->lastUsedTime = ::time(0);

        // Our item is the key followed immediately by the data, so skip
        // past the key.
        const char *cacheData = reinterpret_cast<const char *>(resultPage);
        cacheData += encodedKey.size();
        cacheData++; // Skip trailing null -- now we're pointing to start of data

        if (destination) {
            *destination = QByteArray(cacheData, header->totalItemSize - encodedKey.size() - 1);
        }

        return true;
    }

    return false;
}

void KSharedDataCache::clear()
{
    d->shm->clear();
}

bool KSharedDataCache::contains(const QString &key) const
{
    Private::CacheLocker lock(d);
    if (lock.failed()) {
        return false;
    }

    return d->shm->findNamedEntry(key.toUtf8()) >= 0;
}

void KSharedDataCache::deleteCache(const QString &cacheName)
{
  QString cachePath = KGlobal::dirs()->locateLocal("cache", cacheName + QLatin1String(".kcache"));

    // Note that it is important to simply unlink the file, and not truncate it
    // smaller first to avoid SIGBUS errors and similar with shared memory
    // attached to the underlying inode.
    kDebug(264) << "Removing cache at" << cachePath;
    QFile::remove(cachePath);
}

unsigned KSharedDataCache::totalSize() const
{
    Private::CacheLocker lock(d);
    if (lock.failed()) {
        return 0u;
    }

    return d->shm->cacheSize;
}

unsigned KSharedDataCache::freeSize() const
{
    Private::CacheLocker lock(d);
    if (lock.failed()) {
        return 0u;
    }

    return d->shm->cacheAvail * d->shm->cachePageSize();
}

KSharedDataCache::EvictionPolicy KSharedDataCache::evictionPolicy() const
{
    if (d->m_attached) {
        int policy(d->shm->evictionPolicy);
        return static_cast<EvictionPolicy>(policy);
    }

    return NoEvictionPreference;
}

void KSharedDataCache::setEvictionPolicy(EvictionPolicy newPolicy)
{
    if (d->m_attached) {
        d->shm->evictionPolicy.fetchAndStoreRelease(static_cast<int>(newPolicy));
    }
}

unsigned KSharedDataCache::timestamp() const
{
    if (d->m_attached) {
        return static_cast<unsigned>(d->shm->cacheTimestamp.fetchAndAddAcquire(0));
    }

    return 0;
}

void KSharedDataCache::setTimestamp(unsigned newTimestamp)
{
    if (d->m_attached) {
        d->shm->cacheTimestamp.fetchAndStoreRelease(static_cast<int>(newTimestamp));
    }
}
