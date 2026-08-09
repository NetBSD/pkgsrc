$NetBSD: patch-third__party_blink_renderer_controller_blink__initializer.cc,v 1.24 2026/08/09 06:31:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/controller/blink_initializer.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/blink/renderer/controller/blink_initializer.cc
@@ -87,12 +87,12 @@
 #include "third_party/blink/renderer/platform/fonts/font_cache.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/controller/memory_usage_monitor_posix.h"
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/controller/highest_pmf_reporter.h"
 #endif
 
@@ -266,7 +266,7 @@ void BlinkInitializer::RegisterInterface
       main_thread_task_runner);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   binders.Add<mojom::blink::MemoryUsageMonitorLinux>(
       ConvertToBaseRepeatingCallback(
           CrossThreadBindRepeating(&MemoryUsageMonitorPosix::Bind)),
@@ -319,7 +319,7 @@ void BlinkInitializer::RegisterMemoryWat
   MemorySaverController::Initialize();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Start reporting the highest private memory footprint after the first
   // navigation.
   HighestPmfReporter::Initialize(main_thread_task_runner);
