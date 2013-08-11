$NetBSD: patch-mozilla_ipc_chromium_src_base_platform__thread__posix.cc,v 1.2 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/ipc/chromium/src/base/platform_thread_posix.cc.orig	2013-08-04 03:05:29.000000000 +0000
+++ mozilla/ipc/chromium/src/base/platform_thread_posix.cc
@@ -10,7 +10,9 @@
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
 #elif defined(OS_NETBSD)
+_Pragma("GCC visibility push(default)")
 #include <lwp.h>
+_Pragma("GCC visibility pop")
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
 #include <sys/prctl.h>
@@ -108,7 +110,7 @@ void PlatformThread::SetName(const char*
   pthread_set_name_np(pthread_self(), name);
 #elif defined(OS_NETBSD)
   pthread_setname_np(pthread_self(), "%s", (void *)name);
-#else
+#elif !defined(OS_SOLARIS)
   prctl(PR_SET_NAME, reinterpret_cast<uintptr_t>(name), 0, 0, 0); 
 #endif
 }
