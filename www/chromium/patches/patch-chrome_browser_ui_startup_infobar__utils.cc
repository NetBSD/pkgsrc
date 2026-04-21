$NetBSD: patch-chrome_browser_ui_startup_infobar__utils.cc,v 1.11 2026/04/21 15:21:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/startup/infobar_utils.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/ui/startup/infobar_utils.cc
@@ -46,7 +46,7 @@
 #include "chrome/browser/ui/startup/default_browser_prompt/pin_infobar/pin_infobar_controller.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_controller.h"
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_model.h"
 #endif
@@ -221,7 +221,7 @@ void AddInfoBarsIfNecessary(BrowserWindo
     return;
   }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kSessionRestoreInfobar)) {
     auto* session_restore_infobar_controller =
         session_restore_infobar::SessionRestoreInfobarController::From(browser);
