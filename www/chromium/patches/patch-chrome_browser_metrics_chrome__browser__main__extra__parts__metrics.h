$NetBSD: patch-chrome_browser_metrics_chrome__browser__main__extra__parts__metrics.h,v 1.17 2026/04/10 17:31:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.h.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.h
@@ -29,7 +29,7 @@ class PowerMetricsReporter;
 class ProcessMonitor;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class PressureMetricsReporter;
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -126,7 +126,7 @@ class ChromeBrowserMainExtraPartsMetrics
   std::unique_ptr<web_app::SamplingMetricsProvider> web_app_metrics_provider_;
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Reports pressure metrics.
   std::unique_ptr<PressureMetricsReporter> pressure_metrics_reporter_;
 #endif  // BUILDFLAG(IS_LINUX)
