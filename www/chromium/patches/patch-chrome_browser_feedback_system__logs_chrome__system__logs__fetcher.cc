$NetBSD: patch-chrome_browser_feedback_system__logs_chrome__system__logs__fetcher.cc,v 1.1 2025/05/16 16:08:17 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/feedback/system_logs/chrome_system_logs_fetcher.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/feedback/system_logs/chrome_system_logs_fetcher.cc
@@ -44,7 +44,7 @@
 #include "services/network/public/cpp/shared_url_loader_factory.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/feedback/system_logs/log_sources/ozone_platform_state_dump_source.h"
 #endif
 
@@ -101,7 +101,7 @@ SystemLogsFetcher* BuildChromeSystemLogs
   fetcher->AddSource(std::make_unique<UiHierarchyLogSource>(scrub_data));
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   fetcher->AddSource(std::make_unique<OzonePlatformStateDumpSource>());
 #endif  // BUILDFLAG(IS_LINUX)
 
