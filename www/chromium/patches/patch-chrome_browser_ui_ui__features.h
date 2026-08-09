$NetBSD: patch-chrome_browser_ui_ui__features.h,v 1.24 2026/08/09 06:31:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/ui_features.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/ui_features.h
@@ -30,7 +30,7 @@ BASE_DECLARE_FEATURE(kCreateNewTabGroupA
 
 BASE_DECLARE_FEATURE(kCtrlTabMru);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDseIntegrity);
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
 #endif
@@ -83,7 +83,7 @@ BASE_DECLARE_FEATURE_PARAM(int,
 BASE_DECLARE_FEATURE_PARAM(int, kSeparateDefaultAndPinPromptMessageVersion);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, user may see the session restore UI flow.
 BASE_DECLARE_FEATURE(kSessionRestoreInfobar);
 
@@ -276,7 +276,7 @@ BASE_DECLARE_FEATURE(kManagedProfileRequ
 BASE_DECLARE_FEATURE(kViewsJSAppModalDialog);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUsePortalAccentColor);
 #endif
 
