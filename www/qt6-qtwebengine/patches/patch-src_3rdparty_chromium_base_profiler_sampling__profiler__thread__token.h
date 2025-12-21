$NetBSD: patch-src_3rdparty_chromium_base_profiler_sampling__profiler__thread__token.h,v 1.1 2025/12/21 09:38:15 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.h
@@ -13,7 +13,7 @@
 
 #if BUILDFLAG(IS_ANDROID)
 #include <pthread.h>
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <stdint.h>
 #endif
 
@@ -27,7 +27,7 @@ struct SamplingProfilerThreadToken {
   PlatformThreadId id;
 #if BUILDFLAG(IS_ANDROID)
   pthread_t pthread_id;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Due to the sandbox, we can only retrieve the stack base address for the
   // current thread. We must grab it during
   // GetSamplingProfilerCurrentThreadToken() and not try to get it later.
