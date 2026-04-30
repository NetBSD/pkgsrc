$NetBSD: patch-src_3rdparty_chromium_base_profiler_sampling__profiler__thread__token.cc,v 1.2 2026/04/30 06:39:35 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/base/profiler/sampling_profiler_thread_token.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <pthread.h>
 
 #include "base/profiler/stack_base_address_posix.h"
@@ -18,7 +18,7 @@ SamplingProfilerThreadToken GetSamplingP
   PlatformThreadId id = PlatformThread::CurrentId();
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_APPLE)
   return {id, pthread_self()};
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::optional<uintptr_t> maybe_stack_base =
       GetThreadStackBaseAddress(id, pthread_self());
   return {id, maybe_stack_base};
