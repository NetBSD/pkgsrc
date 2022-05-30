$NetBSD: patch-Source_WTF_wtf_posix_OSAllocatorPOSIX.cpp,v 1.2 2022/05/30 20:40:55 leot Exp $

Set protections for tryReserveUncommittedAligned() on platforms
that have MAP_ALIGNED.

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

--- Source/WTF/wtf/posix/OSAllocatorPOSIX.cpp.orig	2022-02-23 11:41:47.560819000 +0000
+++ Source/WTF/wtf/posix/OSAllocatorPOSIX.cpp
@@ -183,11 +183,15 @@ void* OSAllocator::tryReserveUncommitted
 #define MAP_NORESERVE 0
 #endif
     UNUSED_PARAM(usage);
-    UNUSED_PARAM(writable);
-    UNUSED_PARAM(executable);
     UNUSED_PARAM(jitCageEnabled);
     UNUSED_PARAM(includesGuardPages);
-    void* result = mmap(0, bytes, PROT_NONE, MAP_NORESERVE | MAP_PRIVATE | MAP_ANON | MAP_ALIGNED(getLSBSet(alignment)), -1, 0);
+    int protection = PROT_READ;
+    if (writable)
+        protection |= PROT_WRITE;
+    if (executable)
+        protection |= PROT_EXEC;
+
+    void* result = mmap(0, bytes, protection, MAP_NORESERVE | MAP_PRIVATE | MAP_ANON | MAP_ALIGNED(getLSBSet(alignment)), -1, 0);
     if (result == MAP_FAILED)
         return nullptr;
     if (result)
