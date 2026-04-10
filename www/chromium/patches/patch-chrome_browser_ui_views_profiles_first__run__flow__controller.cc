$NetBSD: patch-chrome_browser_ui_views_profiles_first__run__flow__controller.cc,v 1.1 2026/04/10 17:31:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/first_run_flow_controller.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/ui/views/profiles/first_run_flow_controller.cc
@@ -59,7 +59,7 @@
 #include "chrome/installer/util/shell_util.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/check_deref.h"
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/global_features.h"
@@ -616,7 +616,7 @@ void FirstRunFlowController::RunFinishFl
 }
 
 void FirstRunFlowController::MaybeTriggerHatsSurvey() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No variations seed is available on Mac and Linux at the very first run of
   // Chrome. Check the locale manually to make sure the survey is enabled for
   // only eligible users. Do the locale check before the feature check to avoid
