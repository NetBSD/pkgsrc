$NetBSD: patch-chrome_browser_ui_ui__features.cc,v 1.11 2025/12/11 09:13:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/ui_features.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/browser/ui/ui_features.cc
@@ -39,7 +39,7 @@ BASE_FEATURE(kCloseOmniboxPopupOnInactiv
 BASE_FEATURE(kCreateNewTabGroupAppMenuTopLevel,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables the feature to remove the last confirmation dialog when relaunching
 // to update Chrome.
 BASE_FEATURE(kFewerUpdateConfirmations, base::FEATURE_ENABLED_BY_DEFAULT);
@@ -170,7 +170,7 @@ BASE_FEATURE_PARAM(int,
                    "drop_target_hide_for_os_width",
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
                    32
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                    50
 #else
                    0
@@ -471,7 +471,7 @@ BASE_FEATURE(kViewsFirstRunDialog, base:
 BASE_FEATURE(kViewsJSAppModalDialog, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUsePortalAccentColor, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
 
@@ -677,7 +677,7 @@ bool IsBookmarkTabGroupConversionEnabled
   return base::FeatureList::IsEnabled(kBookmarkTabGroupConversion);
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSessionRestoreInfobar, base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE_PARAM(bool,
