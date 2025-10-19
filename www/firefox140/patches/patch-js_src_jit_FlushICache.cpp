$NetBSD: patch-js_src_jit_FlushICache.cpp,v 1.1 2025/10/19 11:56:56 leot Exp $

NetBSD does not have the Linux-specific membarrier(2) syscall.

--- js/src/jit/FlushICache.cpp.orig	2025-06-13 17:08:49.000000000 +0000
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
@@ -112,6 +118,8 @@ bool CanFlushExecutionContextForAllThrea
   MOZ_ASSERT(state != MemBarrierAvailable::Unset);
   return state == MemBarrierAvailable::Yes;
 
+#  elif defined(__NetBSD__)
+  return false;
 #  else
   // On other platforms, we assume that the syscall for flushing the icache
   // will flush the execution context for other cores.
