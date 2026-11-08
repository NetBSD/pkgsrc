$NetBSD: patch-chrome_browser_ui_ui__features.h,v 1.32 2026/11/08 15:38:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/ui_features.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/ui_features.h
@@ -28,7 +28,7 @@ BASE_DECLARE_FEATURE(kCtrlTabMru);
 
 BASE_DECLARE_FEATURE(kFastFaviconDisplay);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDseIntegrity);
 BASE_DECLARE_FEATURE(kFeedbackDisabledDialog);
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
@@ -98,7 +98,7 @@ BASE_DECLARE_FEATURE_PARAM(int,
 BASE_DECLARE_FEATURE_PARAM(int, kSeparateDefaultAndPinPromptMessageVersion);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, SessionService respects the should_trigger_session_restore
 // flag on BrowserInitState when deciding whether to restore a session for a
 // newly opened browser window.
