$NetBSD: patch-src_3rdparty_chromium_components_feature__engagement_public_feature__constants.cc,v 1.2 2026/04/30 06:39:38 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/feature_engagement/public/feature_constants.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/feature_constants.cc
@@ -34,7 +34,7 @@ bool IsOnDeviceStorageEnabled() {
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 BASE_FEATURE(kEsbDownloadRowPromoFeature,
              "EsbDownloadRowPromo",
@@ -829,7 +829,7 @@ BASE_FEATURE(kDefaultBrowserTriggerCrite
 
 #endif  // BUILDFLAG(IS_IOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
 BASE_FEATURE(kIPHAutofillBnplAffirmOrZipSuggestionFeature,
              "IPH_AutofillBnplAffirmOrZipSuggestion",
@@ -985,7 +985,7 @@ BASE_FEATURE(kIPHScalableIphGamingFeatur
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This can be enabled by default, as the DesktopPWAsLinkCapturing
 // flag is needed for the IPH linked to this feature to work, and
 // use-cases to show the IPH are guarded by that flag.
