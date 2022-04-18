$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_controller_blink__initializer.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/controller/blink_initializer.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/controller/blink_initializer.cc
@@ -68,12 +68,12 @@
 #include "third_party/blink/renderer/controller/oom_intervention_impl.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "third_party/blink/renderer/controller/memory_usage_monitor_posix.h"
 #endif
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_MAC) || defined(OS_WIN)
+    defined(OS_MAC) || defined(OS_WIN) || defined(OS_BSD)
 #include "third_party/blink/renderer/controller/highest_pmf_reporter.h"
 #include "third_party/blink/renderer/controller/user_level_memory_pressure_signal_generator.h"
 #endif
@@ -155,7 +155,7 @@ void InitializeCommon(Platform* platform
 #endif
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_MAC) || defined(OS_WIN)
+    defined(OS_MAC) || defined(OS_WIN) || defined(OS_BSD)
   // Initialize UserLevelMemoryPressureSignalGenerator so it starts monitoring.
   if (UserLevelMemoryPressureSignalGenerator::Enabled())
     UserLevelMemoryPressureSignalGenerator::Instance();
@@ -212,7 +212,7 @@ void BlinkInitializer::RegisterInterface
               main_thread->GetTaskRunner());
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   binders.Add(ConvertToBaseRepeatingCallback(
                   CrossThreadBindRepeating(&MemoryUsageMonitorPosix::Bind)),
               main_thread->GetTaskRunner());
