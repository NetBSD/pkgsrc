$NetBSD: patch-src_3rdparty_chromium_base_profiler_sampling__profiler__thread__token.h,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.h.orig	2020-07-08 21:40:31.000000000 +0000
+++ src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.h
@@ -9,7 +9,7 @@
 #include "base/threading/platform_thread.h"
 #include "build/build_config.h"
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 #include <pthread.h>
 #endif
 
@@ -21,7 +21,7 @@ namespace base {
 // functions used to obtain the stack base address.
 struct SamplingProfilerThreadToken {
   PlatformThreadId id;
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   pthread_t pthread_id;
 #endif
 };
