$NetBSD: patch-chrome_browser_metrics_power_process__monitor.h,v 1.4 2025/07/25 16:17:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/metrics/power/process_monitor.h.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/metrics/power/process_monitor.h
@@ -76,7 +76,7 @@ class ProcessMonitor : public content::B
     std::optional<double> cpu_usage;
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
     // Returns the number of average idle cpu wakeups per second since the last
     // time the metric was sampled.
     int idle_wakeups = 0;
