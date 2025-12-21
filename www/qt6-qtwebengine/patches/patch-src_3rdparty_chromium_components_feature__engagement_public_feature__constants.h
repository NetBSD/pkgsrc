$NetBSD: patch-src_3rdparty_chromium_components_feature__engagement_public_feature__constants.h,v 1.1 2025/12/21 09:38:22 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/feature_engagement/public/feature_constants.h.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/feature_constants.h
@@ -27,7 +27,7 @@ FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHDe
 FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHDummyFeature);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 FEATURE_CONSTANTS_DECLARE_FEATURE(kEsbDownloadRowPromoFeature);
 #endif
@@ -296,7 +296,7 @@ FEATURE_CONSTANTS_DECLARE_FEATURE(kDefau
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 FEATURE_CONSTANTS_DECLARE_FEATURE(
     kIPHAutofillCardInfoRetrievalSuggestionFeature);
 FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHAutofillCreditCardBenefitFeature);
@@ -353,7 +353,7 @@ FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHSc
 FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHScalableIphGamingFeature);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHDesktopPWAsLinkCapturingLaunch);
 FEATURE_CONSTANTS_DECLARE_FEATURE(kIPHDesktopPWAsLinkCapturingLaunchAppInTab);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
