$NetBSD: patch-Source_bmalloc_bmalloc_VMAllocate.h,v 1.1 2018/05/16 18:55:45 jperkin Exp $

Use posix_madvise on SunOS.

--- Source/bmalloc/bmalloc/VMAllocate.h.orig	2018-02-19 07:45:33.000000000 +0000
+++ Source/bmalloc/bmalloc/VMAllocate.h
@@ -198,6 +198,8 @@ inline void vmDeallocatePhysicalPages(vo
     vmValidatePhysical(p, vmSize);
 #if BOS(DARWIN)
     SYSCALL(madvise(p, vmSize, MADV_FREE_REUSABLE));
+#elif defined(__sun)
+    SYSCALL(posix_madvise(p, vmSize, MADV_DONTNEED));
 #else
     SYSCALL(madvise(p, vmSize, MADV_DONTNEED));
 #if BOS(LINUX)
@@ -211,6 +213,8 @@ inline void vmAllocatePhysicalPages(void
     vmValidatePhysical(p, vmSize);
 #if BOS(DARWIN)
     SYSCALL(madvise(p, vmSize, MADV_FREE_REUSE));
+#elif defined(__sun)
+    SYSCALL(posix_madvise(p, vmSize, MADV_NORMAL));
 #else
     SYSCALL(madvise(p, vmSize, MADV_NORMAL));
 #if BOS(LINUX)
