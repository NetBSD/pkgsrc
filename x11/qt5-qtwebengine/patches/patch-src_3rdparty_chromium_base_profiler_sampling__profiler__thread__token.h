$NetBSD: patch-src_3rdparty_chromium_base_profiler_sampling__profiler__thread__token.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.h
@@ -9,7 +9,7 @@
 #include "base/threading/platform_thread.h"
 #include "build/build_config.h"
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <pthread.h>
 #endif
 
@@ -21,7 +21,7 @@ namespace base {
 // functions used to obtain the stack base address.
 struct SamplingProfilerThreadToken {
   PlatformThreadId id;
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   pthread_t pthread_id;
 #endif
 };
