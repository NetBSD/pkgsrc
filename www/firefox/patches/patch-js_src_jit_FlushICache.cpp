$NetBSD: patch-js_src_jit_FlushICache.cpp,v 1.2 2023/08/20 09:31:24 tnn Exp $

NetBSD does not have the Linux-specific membarrier(2) syscall.

--- js/src/jit/FlushICache.cpp.orig	2023-08-15 20:31:19.000000000 +0000
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
@@ -92,6 +98,8 @@ bool CanFlushExecutionContextForAllThrea
 
   computed = true;
   return kernelHasMembarrier;
+#  elif defined(__NetBSD__)
+  return false;
 #  else
   // On other platforms, we assume that the syscall for flushing the icache
   // will flush the execution context for other cores.
