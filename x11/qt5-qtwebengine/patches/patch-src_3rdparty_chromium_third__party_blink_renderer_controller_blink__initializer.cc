$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_controller_blink__initializer.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/controller/blink_initializer.cc.orig	2020-07-15 18:56:47.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/controller/blink_initializer.cc
@@ -66,12 +66,12 @@
 #include "third_party/blink/renderer/controller/oom_intervention_impl.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "third_party/blink/renderer/controller/memory_usage_monitor_posix.h"
 #endif
 
 #if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_MACOSX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
 #include "third_party/blink/renderer/controller/highest_pmf_reporter.h"
 #include "third_party/blink/renderer/controller/user_level_memory_pressure_signal_generator.h"
 #endif
@@ -143,7 +143,7 @@ void InitializeCommon(Platform* platform
 #endif
 
 #if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_MACOSX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   // Initialize UserLevelMemoryPressureSignalGenerator so it starts monitoring.
   if (UserLevelMemoryPressureSignalGenerator::Enabled())
     UserLevelMemoryPressureSignalGenerator::Instance();
@@ -195,7 +195,7 @@ void BlinkInitializer::RegisterInterface
                   &CrashMemoryMetricsReporterImpl::Bind)),
               main_thread->GetTaskRunner());
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   binders.Add(ConvertToBaseRepeatingCallback(
                   CrossThreadBindRepeating(&MemoryUsageMonitorPosix::Bind)),
               main_thread->GetTaskRunner());
