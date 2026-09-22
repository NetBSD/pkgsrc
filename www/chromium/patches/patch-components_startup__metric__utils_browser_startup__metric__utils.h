$NetBSD: patch-components_startup__metric__utils_browser_startup__metric__utils.h,v 1.2 2026/09/22 13:41:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/startup_metric_utils/browser/startup_metric_utils.h.orig	2026-09-14 22:17:16.000000000 +0000
+++ components/startup_metric_utils/browser/startup_metric_utils.h
@@ -197,7 +197,7 @@ class COMPONENT_EXPORT(STARTUP_METRIC_UT
   // Only permit construction from within GetBrowser().
   BrowserStartupMetricRecorder();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns the hard fault count of the current process, or nullopt if it can't
   // be determined.
   std::optional<uint32_t> GetHardFaultCountForCurrentProcess();
