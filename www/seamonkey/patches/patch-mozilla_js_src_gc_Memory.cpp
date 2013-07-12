$NetBSD: patch-mozilla_js_src_gc_Memory.cpp,v 1.1 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/js/src/gc/Memory.cpp.orig	2013-06-20 04:35:07.000000000 +0000
+++ mozilla/js/src/gc/Memory.cpp
@@ -8,6 +8,7 @@
 #include "mozilla/Assertions.h"
 
 #include "jsapi.h"
+#include "jscntxt.h"
 
 #include "js/HeapAPI.h"
 #include "js/Utility.h"
@@ -17,40 +18,35 @@ using namespace js;
 using namespace js::gc;
 
 /* Unused memory decommiting requires the arena size match the page size. */
-static bool
-DecommitEnabled()
+bool
+gc::DecommitEnabled(JSRuntime *rt)
 {
-    return PageSize == ArenaSize;
+    return rt->gcSystemPageSize == ArenaSize;
 }
 
 #if defined(XP_WIN)
 #include "jswin.h"
 #include <psapi.h>
 
-static size_t AllocationGranularity = 0;
-
 void
 gc::InitMemorySubsystem()
 {
     SYSTEM_INFO sysinfo;
     GetSystemInfo(&sysinfo);
-    if (sysinfo.dwPageSize != PageSize) {
-        fprintf(stderr,"SpiderMonkey compiled with incorrect page size; please update js/public/HeapAPI.h.\n");
-        MOZ_CRASH();
-    }
-    AllocationGranularity = sysinfo.dwAllocationGranularity;
+    rt->gcSystemPageSize = sysinfo.dwPageSize;
+    rt->gcSystemAllocGranularity = sysinfo.dwAllocationGranularity;
 }
 
 void *
-gc::MapAlignedPages(size_t size, size_t alignment)
+gc::MapAlignedPages(JSRuntime *rt, size_t size, size_t alignment)
 {
     JS_ASSERT(size >= alignment);
     JS_ASSERT(size % alignment == 0);
-    JS_ASSERT(size % PageSize == 0);
-    JS_ASSERT(alignment % AllocationGranularity == 0);
+    JS_ASSERT(size % rt->gcSystemPageSize == 0);
+    JS_ASSERT(alignment % rt->gcSystemAllocGranularity == 0);
 
     /* Special case: If we want allocation alignment, no further work is needed. */
-    if (alignment == AllocationGranularity) {
+    if (alignment == rt->gcSystemAllocGranularity) {
         return VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
     }
 
@@ -74,7 +70,7 @@ gc::MapAlignedPages(size_t size, size_t 
         if (!p)
             return NULL;
         void *chunkStart = (void *)(uintptr_t(p) + (alignment - (uintptr_t(p) % alignment)));
-        UnmapPages(p, size * 2);
+        UnmapPages(rt, p, size * 2);
         p = VirtualAlloc(chunkStart, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
 
         /* Failure here indicates a race with another thread, so try again. */
@@ -85,26 +81,26 @@ gc::MapAlignedPages(size_t size, size_t 
 }
 
 void
-gc::UnmapPages(void *p, size_t size)
+gc::UnmapPages(JSRuntime *rt, void *p, size_t size)
 {
     JS_ALWAYS_TRUE(VirtualFree(p, 0, MEM_RELEASE));
 }
 
 bool
-gc::MarkPagesUnused(void *p, size_t size)
+gc::MarkPagesUnused(JSRuntime *rt, void *p, size_t size)
 {
-    if (!DecommitEnabled())
-        return false;
+    if (!DecommitEnabled(rt))
+        return true;
 
-    JS_ASSERT(uintptr_t(p) % PageSize == 0);
+    JS_ASSERT(uintptr_t(p) % rt->gcSystemPageSize == 0);
     LPVOID p2 = VirtualAlloc(p, size, MEM_RESET, PAGE_READWRITE);
     return p2 == p;
 }
 
 bool
-gc::MarkPagesInUse(void *p, size_t size)
+gc::MarkPagesInUse(JSRuntime *rt, void *p, size_t size)
 {
-    JS_ASSERT(uintptr_t(p) % PageSize == 0);
+    JS_ASSERT(uintptr_t(p) % rt->gcSystemPageSize == 0);
     return true;
 }
 
@@ -126,12 +122,13 @@ gc::GetPageFaultCount()
 #define OS2_MAX_RECURSIONS  16
 
 void
-gc::InitMemorySubsystem()
+gc::InitMemorySubsystem(JSRuntime *rt)
 {
+    rt->gcSystemPageSize = rt->gcSystemAllocGranularity = ArenaSize;
 }
 
 void
-gc::UnmapPages(void *addr, size_t size)
+gc::UnmapPages(JSRuntime *rt, void *addr, size_t size)
 {
     if (!DosFreeMem(addr))
         return;
@@ -152,7 +149,7 @@ gc::UnmapPages(void *addr, size_t size)
 }
 
 static void *
-gc::MapAlignedPagesRecursively(size_t size, size_t alignment, int& recursions)
+gc::MapAlignedPagesRecursively(JSRuntime *rt, size_t size, size_t alignment, int& recursions)
 {
     if (++recursions >= OS2_MAX_RECURSIONS)
         return NULL;
@@ -178,7 +175,7 @@ gc::MapAlignedPagesRecursively(size_t si
     unsigned long rc = DosQueryMem(&(static_cast<char*>(tmp))[size],
                                    &cb, &flags);
     if (!rc && (flags & PAG_FREE) && cb >= filler) {
-        UnmapPages(tmp, 0);
+        UnmapPages(rt, tmp, 0);
         if (DosAllocMem(&tmp, filler,
                         OBJ_ANY | PAG_COMMIT | PAG_READ | PAG_WRITE)) {
             JS_ALWAYS_TRUE(DosAllocMem(&tmp, filler,
@@ -186,19 +183,19 @@ gc::MapAlignedPagesRecursively(size_t si
         }
     }
 
-    void *p = MapAlignedPagesRecursively(size, alignment, recursions);
-    UnmapPages(tmp, 0);
+    void *p = MapAlignedPagesRecursively(rt, size, alignment, recursions);
+    UnmapPages(rt, tmp, 0);
 
     return p;
 }
 
 void *
-gc::MapAlignedPages(size_t size, size_t alignment)
+gc::MapAlignedPages(JSRuntime *rt, size_t size, size_t alignment)
 {
     JS_ASSERT(size >= alignment);
     JS_ASSERT(size % alignment == 0);
-    JS_ASSERT(size % PageSize == 0);
-    JS_ASSERT(alignment % PageSize == 0);
+    JS_ASSERT(size % rt->gcSystemPageSize == 0);
+    JS_ASSERT(alignment % rt->gcSystemAllocGranularity == 0);
 
     int recursions = -1;
 
@@ -207,7 +204,7 @@ gc::MapAlignedPages(size_t size, size_t 
      * of the right size by recursively allocating blocks of unaligned
      * free memory until only an aligned allocation is possible.
      */
-    void *p = MapAlignedPagesRecursively(size, alignment, recursions);
+    void *p = MapAlignedPagesRecursively(rt, size, alignment, recursions);
     if (p)
         return p;
 
@@ -229,16 +226,16 @@ gc::MapAlignedPages(size_t size, size_t 
 }
 
 bool
-gc::MarkPagesUnused(void *p, size_t size)
+gc::MarkPagesUnused(JSRuntime *rt, void *p, size_t size)
 {
-    JS_ASSERT(uintptr_t(p) % PageSize == 0);
+    JS_ASSERT(uintptr_t(p) % rt->gcSystemPageSize == 0);
     return true;
 }
 
 bool
-gc::MarkPagesInUse(void *p, size_t size)
+gc::MarkPagesInUse(JSRuntime *rt, void *p, size_t size)
 {
-    JS_ASSERT(uintptr_t(p) % PageSize == 0);
+    JS_ASSERT(uintptr_t(p) % rt->gcSystemPageSize == 0);
     return true;
 }
 
@@ -258,17 +255,18 @@ gc::GetPageFaultCount()
 #endif
 
 void
-gc::InitMemorySubsystem()
+gc::InitMemorySubsystem(JSRuntime *rt)
 {
+    rt->gcSystemPageSize = rt->gcSystemAllocGranularity = size_t(sysconf(_SC_PAGESIZE));
 }
 
 void *
-gc::MapAlignedPages(size_t size, size_t alignment)
+gc::MapAlignedPages(JSRuntime *rt, size_t size, size_t alignment)
 {
     JS_ASSERT(size >= alignment);
     JS_ASSERT(size % alignment == 0);
-    JS_ASSERT(size % PageSize == 0);
-    JS_ASSERT(alignment % PageSize == 0);
+    JS_ASSERT(size % rt->gcSystemPageSize == 0);
+    JS_ASSERT(alignment % rt->gcSystemAllocGranularity == 0);
 
     int prot = PROT_READ | PROT_WRITE;
     int flags = MAP_PRIVATE | MAP_ANON | MAP_ALIGN | MAP_NOSYNC;
@@ -280,22 +278,22 @@ gc::MapAlignedPages(size_t size, size_t 
 }
 
 void
-gc::UnmapPages(void *p, size_t size)
+gc::UnmapPages(JSRuntime *rt, void *p, size_t size)
 {
     JS_ALWAYS_TRUE(0 == munmap((caddr_t)p, size));
 }
 
 bool
-gc::MarkPagesUnused(void *p, size_t size)
+gc::MarkPagesUnused(JSRuntime *rt, void *p, size_t size)
 {
-    JS_ASSERT(uintptr_t(p) % PageSize == 0);
+    JS_ASSERT(uintptr_t(p) % rt->gcSystemPageSize == 0);
     return true;
 }
 
 bool
-gc::MarkPagesInUse(void *p, size_t size)
+gc::MarkPagesInUse(JSRuntime *rt, void *p, size_t size)
 {
-    JS_ASSERT(uintptr_t(p) % PageSize == 0);
+    JS_ASSERT(uintptr_t(p) % rt->gcSystemPageSize == 0);
     return true;
 }
 
@@ -313,27 +311,24 @@ gc::GetPageFaultCount()
 #include <unistd.h>
 
 void
-gc::InitMemorySubsystem()
+gc::InitMemorySubsystem(JSRuntime *rt)
 {
-    if (size_t(sysconf(_SC_PAGESIZE)) != PageSize) {
-        fprintf(stderr,"SpiderMonkey compiled with incorrect page size; please update js/public/HeapAPI.h.\n");
-        MOZ_CRASH();
-    }
+    rt->gcSystemPageSize = rt->gcSystemAllocGranularity = size_t(sysconf(_SC_PAGESIZE));
 }
 
 void *
-gc::MapAlignedPages(size_t size, size_t alignment)
+gc::MapAlignedPages(JSRuntime *rt, size_t size, size_t alignment)
 {
     JS_ASSERT(size >= alignment);
     JS_ASSERT(size % alignment == 0);
-    JS_ASSERT(size % PageSize == 0);
-    JS_ASSERT(alignment % PageSize == 0);
+    JS_ASSERT(size % rt->gcSystemPageSize == 0);
+    JS_ASSERT(alignment % rt->gcSystemAllocGranularity == 0);
 
     int prot = PROT_READ | PROT_WRITE;
     int flags = MAP_PRIVATE | MAP_ANON;
 
     /* Special case: If we want page alignment, no further work is needed. */
-    if (alignment == PageSize) {
+    if (alignment == rt->gcSystemAllocGranularity) {
         return mmap(NULL, size, prot, flags, -1, 0);
     }
 
@@ -359,26 +354,26 @@ gc::MapAlignedPages(size_t size, size_t 
 }
 
 void
-gc::UnmapPages(void *p, size_t size)
+gc::UnmapPages(JSRuntime *rt, void *p, size_t size)
 {
     JS_ALWAYS_TRUE(0 == munmap(p, size));
 }
 
 bool
-gc::MarkPagesUnused(void *p, size_t size)
+gc::MarkPagesUnused(JSRuntime *rt, void *p, size_t size)
 {
-    if (!DecommitEnabled())
+    if (!DecommitEnabled(rt))
         return false;
 
-    JS_ASSERT(uintptr_t(p) % PageSize == 0);
+    JS_ASSERT(uintptr_t(p) % rt->gcSystemPageSize == 0);
     int result = madvise(p, size, MADV_DONTNEED);
     return result != -1;
 }
 
 bool
-gc::MarkPagesInUse(void *p, size_t size)
+gc::MarkPagesInUse(JSRuntime *rt, void *p, size_t size)
 {
-    JS_ASSERT(uintptr_t(p) % PageSize == 0);
+    JS_ASSERT(uintptr_t(p) % rt->gcSystemPageSize == 0);
     return true;
 }
 
