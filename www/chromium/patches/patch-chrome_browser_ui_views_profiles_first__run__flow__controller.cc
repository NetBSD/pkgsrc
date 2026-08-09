$NetBSD: patch-chrome_browser_ui_views_profiles_first__run__flow__controller.cc,v 1.8 2026/08/09 06:31:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/first_run_flow_controller.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/views/profiles/first_run_flow_controller.cc
@@ -87,7 +87,7 @@
 #include "chrome/installer/util/shell_util.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/check_deref.h"
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/global_features.h"
@@ -1164,7 +1164,7 @@ bool FirstRunFlowController::AreEffectsE
 }
 
 void FirstRunFlowController::MaybeTriggerHatsSurvey() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No variations seed is available on Mac and Linux at the very first run of
   // Chrome. Check the locale manually to make sure the survey is enabled for
   // only eligible users. Do the locale check before the feature check to avoid
