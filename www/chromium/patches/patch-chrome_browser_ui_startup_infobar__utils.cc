$NetBSD: patch-chrome_browser_ui_startup_infobar__utils.cc,v 1.8 2026/02/15 09:04:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/startup/infobar_utils.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/ui/startup/infobar_utils.cc
@@ -45,7 +45,7 @@
 #include "chrome/browser/ui/startup/default_browser_prompt/pin_infobar/pin_infobar_controller.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_controller.h"
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_model.h"
 #endif
@@ -223,7 +223,7 @@ void AddInfoBarsIfNecessary(BrowserWindo
   }
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kSessionRestoreInfobar)) {
     auto* session_restore_infobar_controller =
         session_restore_infobar::SessionRestoreInfobarController::From(browser);
