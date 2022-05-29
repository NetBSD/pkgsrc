$NetBSD: patch-Source_WTF_wtf_posix_OSAllocatorPOSIX.cpp,v 1.1 2022/05/29 17:47:15 leot Exp $

For NetBSD use the same code paths of OS(LINUX) (there isn't anything
that NetBSD does not support).

This avoid a regression introduced by:

 2022-02-10  Keith Miller  <keith_miller@apple.com>
 
 tryReserveUncommittedAligned should explicitly take the alignment requested
 https://bugs.webkit.org/show_bug.cgi?id=236460
 
 Reviewed by Yusuke Suzuki.
 
 When reducing the size of VA space reserved for Structures, we
 didn't take care to ensure the alignment matched the required
 alignment for our bit mask. To fix this we need to pass the
 original alignment to the allocator as a new parameter.
 
 * heap/StructureAlignedMemoryAllocator.cpp:
   (JSC::StructureMemoryManager::StructureMemoryManager):

Where probably the PROT_* are not readjusted.

XXX: This is a wild-guess that should be double-checked!

--- Source/WTF/wtf/posix/OSAllocatorPOSIX.cpp.orig	2022-02-23 11:41:47.560819000 +0000
+++ Source/WTF/wtf/posix/OSAllocatorPOSIX.cpp
@@ -115,7 +115,7 @@ void* OSAllocator::tryReserveAndCommit(s
 
 void* OSAllocator::tryReserveUncommitted(size_t bytes, Usage usage, bool writable, bool executable, bool jitCageEnabled, bool includesGuardPages)
 {
-#if OS(LINUX)
+#if OS(LINUX) || OS(NETBSD)
     UNUSED_PARAM(usage);
     UNUSED_PARAM(writable);
     UNUSED_PARAM(executable);
@@ -225,7 +225,7 @@ void* OSAllocator::reserveAndCommit(size
 
 void OSAllocator::commit(void* address, size_t bytes, bool writable, bool executable)
 {
-#if OS(LINUX)
+#if OS(LINUX) || OS(NETBSD)
     int protection = PROT_READ;
     if (writable)
         protection |= PROT_WRITE;
@@ -249,7 +249,7 @@ void OSAllocator::commit(void* address, 
 
 void OSAllocator::decommit(void* address, size_t bytes)
 {
-#if OS(LINUX)
+#if OS(LINUX) || OS(NETBSD)
     madvise(address, bytes, MADV_DONTNEED);
     if (mprotect(address, bytes, PROT_NONE))
         CRASH();
