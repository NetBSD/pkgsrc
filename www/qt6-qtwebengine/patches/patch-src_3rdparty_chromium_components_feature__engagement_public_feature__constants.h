$NetBSD: patch-src_3rdparty_chromium_components_feature__engagement_public_feature__constants.h,v 1.2 2026/04/30 06:39:38 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/feature_engagement/public/feature_constants.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/feature_constants.h
@@ -31,7 +31,7 @@ FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHDe
 FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHDummyFeature);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 FEATURE_CONSTANTS_DECLARE_FEATURE(kEsbDownloadRowPromoFeature);
 #endif
@@ -371,7 +371,7 @@ FEATURE_CONSTANTS_DECLARE_FEATURE(kDefau
 
 #endif  // BUILDFLAG(IS_IOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
 FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHAutofillBnplAffirmOrZipSuggestionFeature);
 FEATURE_CONSTANTS_DECLARE_FEATURE(
@@ -435,7 +435,7 @@ FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHSc
 FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHScalableIphGamingFeature);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHDesktopPWAsLinkCapturingLaunch);
 FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHDesktopPWAsLinkCapturingLaunchAppInTab);
 FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHSupervisedUserProfileSigninFeature);
