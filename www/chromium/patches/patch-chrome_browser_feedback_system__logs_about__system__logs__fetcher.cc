$NetBSD: patch-chrome_browser_feedback_system__logs_about__system__logs__fetcher.cc,v 1.30 2026/10/23 15:05:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/feedback/system_logs/about_system_logs_fetcher.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/feedback/system_logs/about_system_logs_fetcher.cc
@@ -35,7 +35,7 @@
 #include "chrome/browser/ash/system_logs/ui_hierarchy_log_source.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/feedback/system_logs/log_sources/ozone_platform_state_dump_source.h"
 #endif
 
@@ -78,7 +78,7 @@ SystemLogsFetcher* BuildAboutSystemLogsF
   fetcher->AddSource(std::make_unique<KeyboardInfoLogSource>());
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   fetcher->AddSource(std::make_unique<OzonePlatformStateDumpSource>());
 #endif  // BUILDFLAG(IS_LINUX)
 
