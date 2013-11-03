$NetBSD: patch-media_webrtc_trunk_webrtc_system__wrappers_source_thread__posix.cc,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- media/webrtc/trunk/webrtc/system_wrappers/source/thread_posix.cc.orig	2013-09-10 03:43:47.000000000 +0000
+++ media/webrtc/trunk/webrtc/system_wrappers/source/thread_posix.cc
@@ -272,7 +272,7 @@ bool ThreadPosix::Start(unsigned int& th
 
 // CPU_ZERO and CPU_SET are not available in NDK r7, so disable
 // SetAffinity on Android for now.
-#if defined(__FreeBSD__) || (defined(WEBRTC_LINUX) && (!defined(WEBRTC_ANDROID)) && (!defined(WEBRTC_GONK)))
+#if defined(__FreeBSD__) || defined(__NetBSD__) || (defined(WEBRTC_LINUX) && (!defined(WEBRTC_ANDROID)) && (!defined(WEBRTC_GONK)))
 bool ThreadPosix::SetAffinity(const int* processor_numbers,
                               const unsigned int amount_of_processors) {
   if (!processor_numbers || (amount_of_processors == 0)) {
@@ -280,20 +280,34 @@ bool ThreadPosix::SetAffinity(const int*
   }
 #if defined(__FreeBSD__)
   cpuset_t mask;
+#elif defined(__NetBSD__)
+  cpuset_t *mask;
 #else
   cpu_set_t mask;
 #endif
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
 #if defined(__FreeBSD__)
   const int result = pthread_setaffinity_np(thread_,
                              sizeof(mask),
                              &mask);
+#elif defined(__NetBSD__)
+  const int result = pthread_setaffinity_np(thread_,
+                             sizeof(mask),
+                             mask);
 #elif defined(WEBRTC_ANDROID) || defined(WEBRTC_GONK)
   // Android.
   const int result = syscall(__NR_sched_setaffinity,
