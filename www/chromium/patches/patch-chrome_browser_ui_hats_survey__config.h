$NetBSD: patch-chrome_browser_ui_hats_survey__config.h,v 1.1 2025/11/04 14:55:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/hats/survey_config.h.orig	2025-10-24 16:42:30.000000000 +0000
+++ chrome/browser/ui/hats/survey_config.h
@@ -89,7 +89,7 @@ extern const char kHatsSurveyTriggerSafe
 extern const char kHatsSurveyOrganicTriggerSafetyHubAndroid[];
 #endif  // #if !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kHatsSurveyTriggerPrivacySandboxWhatsNewSurvey[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
