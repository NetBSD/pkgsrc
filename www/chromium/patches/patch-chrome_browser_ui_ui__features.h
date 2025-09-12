$NetBSD: patch-chrome_browser_ui_ui__features.h,v 1.7 2025/09/12 16:02:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/ui_features.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/ui/ui_features.h
@@ -28,7 +28,7 @@ BASE_DECLARE_FEATURE(kAllowEyeDropperWGC
 
 BASE_DECLARE_FEATURE(kCloseOmniboxPopupOnInactiveAreaClick);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
 #endif
 
@@ -292,7 +292,7 @@ BASE_DECLARE_FEATURE(kViewsFirstRunDialo
 BASE_DECLARE_FEATURE(kViewsJSAppModalDialog);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUsePortalAccentColor);
 #endif
 
