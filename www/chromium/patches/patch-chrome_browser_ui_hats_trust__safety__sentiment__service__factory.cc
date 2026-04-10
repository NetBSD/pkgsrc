$NetBSD: patch-chrome_browser_ui_hats_trust__safety__sentiment__service__factory.cc,v 1.13 2026/04/10 17:31:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/hats/trust_safety_sentiment_service_factory.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/ui/hats/trust_safety_sentiment_service_factory.cc
@@ -59,7 +59,7 @@ TrustSafetySentimentServiceFactory::Buil
   // TrustSafetySentimentSurvey is conducted only for Windows, MacOS and Linux
   // currently.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS))
 
   // TrustSafetySentimentSurvey is conducted only in English currently.
   const std::string& application_locale =
