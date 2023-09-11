$NetBSD: patch-js_src_jit_FlushICache.cpp,v 1.1 2023/09/11 12:33:25 ryoon Exp $

NetBSD does not have the Linux-specific membarrier(2) syscall.

--- js/src/jit/FlushICache.cpp.orig	2022-09-08 19:35:33.000000000 +0000
+++ js/src/jit/FlushICache.cpp
@@ -31,12 +31,18 @@
 #    elif defined(__android__)
 #      include <sys/syscall.h>
 #      include <unistd.h>
+#    elif defined(__NetBSD__)
+       // nothing
 #    else
 #      error "Missing platform-specific declarations for membarrier syscall!"
 #    endif  // __linux__ / ANDROID
 
 static int membarrier(int cmd, int flags) {
+#if defined(__NetBSD__)
+  return ENOSYS;
+#else
   return syscall(__NR_membarrier, cmd, flags);
+#endif
 }
 
 // These definitions come from the Linux kernel source, for kernels before 4.16
