$NetBSD: patch-third__party_blink_renderer_controller_blink__initializer.cc,v 1.16 2026/03/14 12:40:40 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/controller/blink_initializer.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ third_party/blink/renderer/controller/blink_initializer.cc
@@ -84,12 +84,12 @@
 #include "third_party/blink/renderer/controller/user_level_memory_pressure_signal_generator.h"
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
 
@@ -256,7 +256,7 @@ void BlinkInitializer::RegisterInterface
       main_thread_task_runner);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   binders.Add<mojom::blink::MemoryUsageMonitorLinux>(
       ConvertToBaseRepeatingCallback(
           CrossThreadBindRepeating(&MemoryUsageMonitorPosix::Bind)),
@@ -304,7 +304,7 @@ void BlinkInitializer::RegisterMemoryWat
   MemorySaverController::Initialize();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Start reporting the highest private memory footprint after the first
   // navigation.
   HighestPmfReporter::Initialize(main_thread_task_runner);
