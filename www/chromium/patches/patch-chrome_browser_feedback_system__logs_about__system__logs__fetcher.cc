$NetBSD: patch-chrome_browser_feedback_system__logs_about__system__logs__fetcher.cc,v 1.6 2025/09/12 16:02:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/feedback/system_logs/about_system_logs_fetcher.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/feedback/system_logs/about_system_logs_fetcher.cc
@@ -38,7 +38,7 @@
 #include "chrome/browser/ash/system_logs/ui_hierarchy_log_source.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/feedback/system_logs/log_sources/ozone_platform_state_dump_source.h"
 #endif
 
@@ -85,7 +85,7 @@ SystemLogsFetcher* BuildAboutSystemLogsF
   fetcher->AddSource(std::make_unique<KeyboardInfoLogSource>());
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   fetcher->AddSource(std::make_unique<OzonePlatformStateDumpSource>());
 #endif  // BUILDFLAG(IS_LINUX)
 
