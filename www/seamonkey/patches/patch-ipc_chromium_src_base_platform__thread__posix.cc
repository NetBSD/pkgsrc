$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.9 2013/01/07 21:55:30 ryoon Exp $

--- mozilla/ipc/chromium/src/base/platform_thread_posix.cc.orig	2012-11-18 10:19:38.000000000 +0000
+++ mozilla/ipc/chromium/src/base/platform_thread_posix.cc
@@ -9,16 +9,30 @@
 
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
+#elif defined(OS_NETBSD)
+#include <lwp.h>
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
-#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
 #include <sys/prctl.h>
-#elif !defined(__NetBSD__)
-#include <pthread_np.h>
+#elif defined(OS_FREEBSD)
+#include <sys/param.h>
+#if __FreeBSD_version > 802500
+#include <sys/thr.h>
+#else
+_Pragma("GCC visibility push(default)")
+extern "C" int thr_self(long *);
+_Pragma("GCC visibility pop")
 #endif
+#endif
+
+#if !defined(OS_MACOSX)
 #include <unistd.h>
 #endif
 
+#if defined(OS_BSD) && !defined(OS_NETBSD)
+#include <pthread_np.h>
+#endif
+
 #if defined(OS_MACOSX)
 namespace base {
 void InitThreading();
@@ -38,9 +52,20 @@ PlatformThreadId PlatformThread::Current
   // into the kernel.
 #if defined(OS_MACOSX)
   return mach_thread_self();
-#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
-  // TODO(BSD): find a better thread ID
-  return (intptr_t)(pthread_self());
+#elif defined(OS_NETBSD)
+  return _lwp_self();
+#elif defined(OS_DRAGONFLY)
+  return lwp_gettid();
+#elif defined(OS_FREEBSD)
+#  if __FreeBSD_version > 900030
+    return pthread_getthreadid_np();
+#  else
+    long lwpid;
+    thr_self(&lwpid);
+    return lwpid;
+#  endif
+#elif defined(OS_OPENBSD)
+  return (intptr_t) (pthread_self());
 #elif defined(OS_LINUX)
   return syscall(__NR_gettid);
 #endif
@@ -83,9 +108,9 @@ void PlatformThread::SetName(const char*
   // Note that glibc also has a 'pthread_setname_np' api, but it may not be
   // available everywhere and it's only benefit over using prctl directly is
   // that it can set the name of threads other than the current thread.
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(OS_BSD) && !defined(OS_NETBSD)
   pthread_set_name_np(pthread_self(), name);
-#elif defined(__NetBSD__)
+#elif defined(OS_NETBSD)
   pthread_setname_np(pthread_self(), "%s", (void *)name);
 #else
   prctl(PR_SET_NAME, reinterpret_cast<uintptr_t>(name), 0, 0, 0); 
