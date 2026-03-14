$NetBSD: patch-chrome_browser_ui_browser__window_internal_browser__window__features.cc,v 1.8 2026/03/14 12:40:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_window/internal/browser_window_features.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/ui/browser_window/internal/browser_window_features.cc
@@ -160,7 +160,7 @@
 #include "chrome/browser/ui/startup/default_browser_prompt/pin_infobar/pin_infobar_controller.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_controller.h"
 #endif
 
@@ -434,7 +434,7 @@ void BrowserWindowFeatures::Init(Browser
   context_highlight_window_feature_ =
       std::make_unique<ContextHighlightWindowFeature>(*browser);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   profile_customization_bubble_sync_controller_ =
       std::make_unique<ProfileCustomizationBubbleSyncController>(browser,
                                                                  profile);
