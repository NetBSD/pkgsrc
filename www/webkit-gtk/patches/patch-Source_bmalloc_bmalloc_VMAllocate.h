$NetBSD: patch-Source_bmalloc_bmalloc_VMAllocate.h,v 1.3 2019/09/10 22:10:04 leot Exp $

NetBSD has MADV_FREE too.
Use posix_madvise on SunOS.

--- Source/bmalloc/bmalloc/VMAllocate.h.orig	2019-08-28 11:46:33.000000000 +0000
+++ Source/bmalloc/bmalloc/VMAllocate.h
@@ -201,8 +201,10 @@ inline void vmDeallocatePhysicalPages(vo
     vmValidatePhysical(p, vmSize);
 #if BOS(DARWIN)
     SYSCALL(madvise(p, vmSize, MADV_FREE_REUSABLE));
-#elif BOS(FREEBSD)
+#elif BOS(FREEBSD) || BOS(NETBSD)
     SYSCALL(madvise(p, vmSize, MADV_FREE));
+#elif BOS(SOLARIS)
+    SYSCALL(posix_madvise(p, vmSize, MADV_DONTNEED));
 #else
     SYSCALL(madvise(p, vmSize, MADV_DONTNEED));
 #if BOS(LINUX)
@@ -216,6 +218,8 @@ inline void vmAllocatePhysicalPages(void
     vmValidatePhysical(p, vmSize);
 #if BOS(DARWIN)
     SYSCALL(madvise(p, vmSize, MADV_FREE_REUSE));
+#elif BOS(SOLARIS)
+    SYSCALL(posix_madvise(p, vmSize, MADV_NORMAL));
 #else
     SYSCALL(madvise(p, vmSize, MADV_NORMAL));
 #if BOS(LINUX)
