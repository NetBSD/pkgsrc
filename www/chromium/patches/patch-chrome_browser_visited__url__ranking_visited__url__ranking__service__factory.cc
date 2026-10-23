$NetBSD: patch-chrome_browser_visited__url__ranking_visited__url__ranking__service__factory.cc,v 1.31 2026/10/23 15:05:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/visited_url_ranking/visited_url_ranking_service_factory.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/visited_url_ranking/visited_url_ranking_service_factory.cc
@@ -47,7 +47,7 @@
 #include "components/visited_url_ranking/public/visited_url_ranking_service.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/visited_url_ranking/desktop_tab_model_url_visit_data_fetcher.h"
 #elif BUILDFLAG(IS_ANDROID)
 #include "chrome/browser/visited_url_ranking/android_tab_model_url_visit_data_fetcher.h"
@@ -121,7 +121,7 @@ VisitedURLRankingServiceFactory::BuildSe
 
   std::map<Fetcher, std::unique_ptr<URLVisitDataFetcher>> data_fetchers;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   data_fetchers.emplace(
       Fetcher::kTabModel,
       std::make_unique<visited_url_ranking::DesktopTabModelURLVisitDataFetcher>(
