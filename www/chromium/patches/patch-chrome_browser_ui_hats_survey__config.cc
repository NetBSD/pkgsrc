$NetBSD: patch-chrome_browser_ui_hats_survey__config.cc,v 1.29 2026/11/19 19:45:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/hats/survey_config.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/hats/survey_config.cc
@@ -365,7 +365,7 @@ std::vector<hats::SurveyConfig> GetAllSu
       &features::kHappinessTrackingSurveysForWallpaperSearch,
       kHatsSurveyTriggerWallpaperSearch);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Scheduled Restart survey.
   // LINT.IfChange(ScheduledRestartHatsPsdFields)
   survey_configs.emplace_back(
