$NetBSD: patch-chrome_browser_metrics_power_process__monitor.cc,v 1.31 2026/10/23 15:05:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/metrics/power/process_monitor.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/metrics/power/process_monitor.cc
@@ -69,7 +69,7 @@ class ProcessMetricsDelegateImpl : publi
   }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   int GetIdleWakeupsPerSecond() override {
     return process_metrics_->GetIdleWakeupsPerSecond();
   }
@@ -106,7 +106,7 @@ ProcessMonitor::Metrics SampleMetrics(Pr
       process_metrics.GetPlatformIndependentCPUUsage());
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   metrics.idle_wakeups = process_metrics.GetIdleWakeupsPerSecond();
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -124,7 +124,7 @@ void ScaleMetrics(ProcessMonitor::Metric
   }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   metrics->idle_wakeups *= factor;
 #endif
 
@@ -208,7 +208,7 @@ ProcessMonitor::Metrics& operator+=(Proc
   }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   lhs.idle_wakeups += rhs.idle_wakeups;
 #endif
 
