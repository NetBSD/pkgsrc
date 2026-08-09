$NetBSD: patch-chrome_browser_metrics_power_process__metrics__recorder__util.cc,v 1.24 2026/08/09 06:31:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/metrics/power/process_metrics_recorder_util.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/metrics/power/process_metrics_recorder_util.cc
@@ -65,7 +65,7 @@ void RecordProcessHistograms(const std::
                              const ProcessMonitor::Metrics& metrics) {
   RecordAverageCPUUsage(histogram_suffix, metrics.cpu_usage);
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   base::UmaHistogramCounts10000(
       base::StrCat({"PerformanceMonitor.IdleWakeups2.", histogram_suffix}),
       metrics.idle_wakeups);
