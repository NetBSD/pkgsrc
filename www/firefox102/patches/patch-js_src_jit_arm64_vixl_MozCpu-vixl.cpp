$NetBSD: patch-js_src_jit_arm64_vixl_MozCpu-vixl.cpp,v 1.1 2022/07/21 23:56:39 nia Exp $

NetBSD/aarch64 does not have the Linux-specific membarrier(2) syscall.

--- js/src/jit/arm64/vixl/MozCpu-vixl.cpp.orig	2020-11-12 18:04:48.000000000 +0000
+++ js/src/jit/arm64/vixl/MozCpu-vixl.cpp
@@ -42,6 +42,8 @@
 #   elif defined(__ANDROID__)
 #    include <sys/syscall.h>
 #    include <unistd.h>
+#   elif defined(__NetBSD__)
+     // nothing
 #   else
 #    error "Missing platform-specific declarations for membarrier syscall!"
 #   endif // __linux__ / ANDROID
@@ -49,7 +51,11 @@
 #  include "vm/JSContext.h" // TlsContext
 
 static int membarrier(int cmd, int flags) {
+#if defined(__NetBSD__)
+    return ENOSYS;
+#else
     return syscall(__NR_membarrier, cmd, flags);
+#endif
 }
 
 // These definitions come from the Linux kernel source, for kernels before 4.16
@@ -116,7 +122,9 @@ uint32_t CPU::GetCacheType() {
 }
 
 bool CPU::CanFlushICacheFromBackgroundThreads() {
-#if defined(__aarch64__) && (defined(__linux__) || defined(__android__))
+#if defined(__NetBSD__) && defined(__aarch64__)
+  return false;
+#elif defined(__aarch64__) && (defined(__linux__) || defined(__android__))
   // On linux, check the kernel supports membarrier(2), that is, it's a kernel
   // above Linux 4.16 included.
   //
