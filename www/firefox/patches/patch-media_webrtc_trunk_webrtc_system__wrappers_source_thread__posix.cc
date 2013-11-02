$NetBSD: patch-media_webrtc_trunk_webrtc_system__wrappers_source_thread__posix.cc,v 1.4 2013/11/02 22:57:55 ryoon Exp $

--- media/webrtc/trunk/webrtc/system_wrappers/source/thread_posix.cc.orig	2013-10-25 22:27:35.000000000 +0000
+++ media/webrtc/trunk/webrtc/system_wrappers/source/thread_posix.cc
@@ -278,20 +278,34 @@ bool ThreadPosix::SetAffinity(const int*
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
