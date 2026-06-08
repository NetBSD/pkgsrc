$NetBSD: patch-chrome_browser_ui_ui__features.cc,v 1.21 2026/06/08 13:12:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/ui_features.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ chrome/browser/ui/ui_features.cc
@@ -42,7 +42,7 @@ BASE_FEATURE(kMenuSimplification, base::
 BASE_FEATURE(kTabGroupColorRefresh, base::FEATURE_DISABLED_BY_DEFAULT);
 BASE_FEATURE(kWebuiRefresh2026, base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDseIntegrity, base::FEATURE_ENABLED_BY_DEFAULT);
 // Enables the feature to remove the last confirmation dialog when relaunching
 // to update Chrome.
@@ -231,7 +231,7 @@ BASE_FEATURE(kManagedProfileRequiredInte
 BASE_FEATURE(kViewsJSAppModalDialog, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUsePortalAccentColor, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
 
@@ -352,7 +352,7 @@ bool IsBookmarkTabGroupConversionEnabled
   return base::FeatureList::IsEnabled(kBookmarkTabGroupConversion);
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSessionRestoreInfobar, base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE_PARAM(bool,
