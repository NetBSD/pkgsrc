$NetBSD: patch-chrome_browser_feedback_system__logs_chrome__system__logs__fetcher.cc,v 1.6 2025/09/12 16:02:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/feedback/system_logs/chrome_system_logs_fetcher.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/feedback/system_logs/chrome_system_logs_fetcher.cc
@@ -45,7 +45,7 @@
 #include "services/network/public/cpp/shared_url_loader_factory.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/feedback/system_logs/log_sources/ozone_platform_state_dump_source.h"
 #endif
 
@@ -102,7 +102,7 @@ SystemLogsFetcher* BuildChromeSystemLogs
   fetcher->AddSource(std::make_unique<UiHierarchyLogSource>(scrub_data));
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   fetcher->AddSource(std::make_unique<OzonePlatformStateDumpSource>());
 #endif  // BUILDFLAG(IS_LINUX)
 
