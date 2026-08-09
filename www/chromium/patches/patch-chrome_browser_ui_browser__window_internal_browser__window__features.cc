$NetBSD: patch-chrome_browser_ui_browser__window_internal_browser__window__features.cc,v 1.16 2026/08/09 06:31:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_window/internal/browser_window_features.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/browser_window/internal/browser_window_features.cc
@@ -213,7 +213,7 @@
 #include "chrome/browser/ui/startup/default_browser_prompt/pin_infobar/pin_infobar_controller.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_controller.h"
 #endif
 
@@ -460,7 +460,7 @@ void BrowserWindowFeatures::Init(Browser
                                                                  browser);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   profile_customization_bubble_sync_controller_ =
       std::make_unique<ProfileCustomizationBubbleSyncController>(browser,
                                                                  profile);
