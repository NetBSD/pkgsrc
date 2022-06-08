$NetBSD: patch-Source_WTF_wtf_posix_OSAllocatorPOSIX.cpp,v 1.3 2022/06/08 20:56:50 leot Exp $

Set protections for tryReserveUncommittedAligned() on platforms
that have MAP_ALIGNED.

This avoid a regression introduced by 247105@main.

Shared and applied upstream via <https://bugs.webkit.org/show_bug.cgi?id=241386>.

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
