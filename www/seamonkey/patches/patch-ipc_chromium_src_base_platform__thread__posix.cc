$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.2 2011/08/01 08:17:17 tnn Exp $

--- mozilla/ipc/chromium/src/base/platform_thread_posix.cc.orig	2011-06-15 21:57:27.000000000 +0000
+++ mozilla/ipc/chromium/src/base/platform_thread_posix.cc
@@ -9,6 +9,8 @@
 
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
+#elif defined(OS_NETBSD)
+#include <lwp.h>
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
 #include <unistd.h>
@@ -33,6 +35,10 @@ PlatformThreadId PlatformThread::Current
   // into the kernel.
 #if defined(OS_MACOSX)
   return mach_thread_self();
+#elif defined(OS_NETBSD)
+  return _lwp_self();
+#elif defined(OS_DRAGONFLY)
+  return lwp_gettid();
 #elif defined(OS_LINUX)
   return syscall(__NR_gettid);
 #endif
