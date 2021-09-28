$NetBSD: patch-Source_bmalloc_bmalloc_VMAllocate.h,v 1.4 2021/09/28 22:11:54 leot Exp $

NetBSD has MADV_FREE too.
Use posix_madvise on SunOS.

--- Source/bmalloc/bmalloc/VMAllocate.h.orig	2021-09-01 09:16:51.000000000 +0000
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
@@ -220,6 +222,8 @@ inline void vmAllocatePhysicalPages(void
     // For the Darwin platform, we don't need to call madvise(..., MADV_FREE_REUSE)
     // to commit physical memory to back a range of allocated virtual memory.
     // Instead the kernel will commit pages as they are touched.
+#elif BOS(SOLARIS)
+    SYSCALL(posix_madvise(p, vmSize, MADV_NORMAL));
 #else
     SYSCALL(madvise(p, vmSize, MADV_NORMAL));
 #if BOS(LINUX)
