$NetBSD: patch-chrome_browser_metrics_chrome__browser__main__extra__parts__metrics.cc,v 1.33 2026/11/19 19:45:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc
@@ -85,7 +85,7 @@
 #include "chrome/browser/metrics/power/process_monitor.h"
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if defined(__GLIBC__)
 #include <gnu/libc-version.h>
 #endif  // defined(__GLIBC__)
@@ -120,7 +120,7 @@
 #include "components/user_manager/user_manager.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/power_metrics/system_power_monitor.h"
 #endif
 
@@ -946,7 +946,7 @@ void RecordStartupMetrics() {
 
   // Record whether Chrome is the default browser or not.
   // Disabled on Linux due to hanging browser tests, see crbug.com/40770414.
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_WIN)
   // Read before GetDefaultBrowser(), which updates the beacons.
   const default_browser::DefaultBrowserBeacons beacons =
@@ -1255,11 +1255,11 @@ void ChromeBrowserMainExtraPartsMetrics:
       std::make_unique<web_app::SamplingMetricsProvider>();
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   pressure_metrics_reporter_ = std::make_unique<PressureMetricsReporter>();
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   power_metrics::SystemPowerMonitor::Initialize();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
