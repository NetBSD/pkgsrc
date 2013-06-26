$NetBSD: patch-media_webrtc_trunk_webrtc_system__wrappers_source_thread__posix.cc,v 1.2 2013/06/26 11:32:12 ryoon Exp $

--- media/webrtc/trunk/webrtc/system_wrappers/source/thread_posix.cc.orig	2013-06-17 22:13:20.000000000 +0000
+++ media/webrtc/trunk/webrtc/system_wrappers/source/thread_posix.cc
@@ -59,6 +59,19 @@
 #include <sys/prctl.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <lwp.h>
+#include <pthread.h>
+#include <sched.h>
+#elif defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/thr.h>
+#endif
+
+#if defined(WEBRTC_BSD) && !defined(__NetBSD__)
+#include <pthread_np.h>
+#endif
+
 #include "webrtc/system_wrappers/interface/critical_section_wrapper.h"
 #include "webrtc/system_wrappers/interface/event_wrapper.h"
 #include "webrtc/system_wrappers/interface/trace.h"
@@ -141,6 +154,20 @@ uint32_t ThreadWrapper::GetThreadId() {
   return static_cast<uint32_t>(syscall(__NR_gettid));
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   return pthread_mach_thread_np(pthread_self());
+#elif defined(__NetBSD__)
+  return _lwp_self();
+#elif defined(__DragonFly__)
+  return lwp_gettid();
+#elif defined(__OpenBSD__)
+  return reinterpret_cast<uintptr_t> (pthread_self());
+#elif defined(__FreeBSD__)
+#  if __FreeBSD_version > 900030
+    return pthread_getthreadid_np();
+#  else
+    long lwpid;
+    thr_self(&lwpid);
+    return lwpid;
+#  endif
 #else
   return reinterpret_cast<uint32_t>(pthread_self());
 #endif
@@ -172,7 +199,7 @@ ThreadPosix::~ThreadPosix() {
   delete crit_state_;
 }
 
-#define HAS_THREAD_ID !defined(WEBRTC_IOS) && !defined(WEBRTC_MAC)
+#define HAS_THREAD_ID !defined(WEBRTC_IOS) && !defined(WEBRTC_MAC) && !defined(WEBRTC_BSD)
 
 bool ThreadPosix::Start(unsigned int& thread_id)
 {
@@ -237,21 +264,43 @@ bool ThreadPosix::Start(unsigned int& th
 
 // CPU_ZERO and CPU_SET are not available in NDK r7, so disable
 // SetAffinity on Android for now.
-#if (defined(WEBRTC_LINUX) && (!defined(WEBRTC_ANDROID)) && (!defined(WEBRTC_GONK)))
+#if defined(__FreeBSD__) || defined(__NetBSD__) || (defined(WEBRTC_LINUX) && (!defined(WEBRTC_ANDROID)) && (!defined(WEBRTC_GONK)))
 bool ThreadPosix::SetAffinity(const int* processor_numbers,
                               const unsigned int amount_of_processors) {
   if (!processor_numbers || (amount_of_processors == 0)) {
     return false;
   }
+#if defined(__FreeBSD__)
+  cpuset_t mask;
+#elif defined(__NetBSD__)
+  cpuset_t *mask;
+#else
   cpu_set_t mask;
+#endif
+#if defined(__NetBSD__)
+  cpuset_zero(mask);
+#else
   CPU_ZERO(&mask);
+#endif
 
   for (unsigned int processor = 0;
        processor < amount_of_processors;
        ++processor) {
+#if defined(__NetBSD__)
+    cpuset_set(processor_numbers[processor], mask);
+#else
     CPU_SET(processor_numbers[processor], &mask);
+#endif
   }
-#if defined(WEBRTC_ANDROID) || defined(WEBRTC_GONK)
+#if defined(__FreeBSD__)
+  const int result = pthread_setaffinity_np(thread_,
+                             sizeof(mask),
+                             &mask);
+#elif defined(__NetBSD__)
+  const int result = pthread_setaffinity_np(thread_,
+                             sizeof(mask),
+                             mask);
+#elif defined(WEBRTC_ANDROID) || defined(WEBRTC_GONK)
   // Android.
   const int result = syscall(__NR_sched_setaffinity,
                              pid_,
@@ -325,6 +374,10 @@ void ThreadPosix::Run() {
   if (set_thread_name_) {
 #ifdef WEBRTC_LINUX
     prctl(PR_SET_NAME, (unsigned long)name_, 0, 0, 0);
+#elif defined(__NetBSD__)
+        pthread_setname_np(pthread_self(), "%s", (void *)name_);
+#elif defined(WEBRTC_BSD)
+        pthread_set_name_np(pthread_self(), name_);
 #endif
     WEBRTC_TRACE(kTraceStateInfo, kTraceUtility, -1,
                  "Thread with name:%s started ", name_);
