$NetBSD: patch-chrome_browser_ui_tab__helpers.cc,v 1.30 2026/10/16 15:30:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/tab_helpers.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/ui/tab_helpers.cc
@@ -210,7 +210,7 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/hats/hats_helper.h"
 #include "chrome/browser/ui/performance_controls/performance_controls_hats_service_factory.h"
 #include "chrome/browser/ui/shared_highlighting/shared_highlighting_promo.h"
@@ -765,12 +765,12 @@ void TabHelpers::AttachTabHelpers(WebCon
   webapps::PreRedirectionURLObserver::CreateForWebContents(web_contents);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metrics::DesktopSessionDurationObserver::CreateForWebContents(web_contents);
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kHappinessTrackingSurveysForDesktopDemo) ||
       base::FeatureList::IsEnabled(features::kTrustSafetySentimentSurvey) ||
