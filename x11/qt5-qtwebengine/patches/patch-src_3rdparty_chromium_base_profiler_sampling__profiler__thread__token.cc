$NetBSD: patch-src_3rdparty_chromium_base_profiler_sampling__profiler__thread__token.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.cc
@@ -7,7 +7,7 @@
 namespace base {
 
 SamplingProfilerThreadToken GetSamplingProfilerCurrentThreadToken() {
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return {PlatformThread::CurrentId(), pthread_self()};
 #else
   return {PlatformThread::CurrentId()};
