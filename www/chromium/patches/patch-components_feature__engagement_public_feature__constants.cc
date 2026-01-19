$NetBSD: patch-components_feature__engagement_public_feature__constants.cc,v 1.14 2026/01/19 16:14:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/feature_engagement/public/feature_constants.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/feature_engagement/public/feature_constants.cc
@@ -32,7 +32,7 @@ bool IsOnDeviceStorageEnabled() {
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 BASE_FEATURE(kEsbDownloadRowPromoFeature,
              "EsbDownloadRowPromo",
@@ -226,7 +226,7 @@ BASE_FEATURE(kIPHShoppingCollectionFeatu
 BASE_FEATURE(kIPHSideBySidePinnableFeature,
              "IPH_SideBySidePinnableFeature",
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -234,7 +234,7 @@ BASE_FEATURE(kIPHSideBySidePinnableFeatu
 );
 BASE_FEATURE(kIPHSideBySideTabSwitchFeature,
              "IPH_SideBySideTabSwitchFeature",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -872,7 +872,7 @@ BASE_FEATURE(kIPHiOSGeminiContextualCueC
 
 #endif  // BUILDFLAG(IS_IOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
 BASE_FEATURE(kIPHAutofillBnplAffirmOrZipSuggestionFeature,
              "IPH_AutofillBnplAffirmOrZipSuggestion",
@@ -1031,7 +1031,7 @@ BASE_FEATURE(kIPHScalableIphGamingFeatur
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This can be enabled by default, as the DesktopPWAsLinkCapturing
 // flag is needed for the IPH linked to this feature to work, and
 // use-cases to show the IPH are guarded by that flag.
