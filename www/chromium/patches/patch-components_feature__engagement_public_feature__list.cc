$NetBSD: patch-components_feature__engagement_public_feature__list.cc,v 1.26 2026/09/22 13:41:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/feature_engagement/public/feature_list.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ components/feature_engagement/public/feature_list.cc
@@ -251,7 +251,7 @@ const base::Feature* const kAllFeatures[
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
     &kEsbDownloadRowPromoFeature,
 #endif
@@ -341,7 +341,7 @@ const base::Feature* const kAllFeatures[
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     // keep-sorted start case=no
     &kIPHAutofillAccountNameEmailSuggestionFeature,
     &kIPHAutofillAiOptInFeature,
@@ -374,7 +374,7 @@ const base::Feature* const kAllFeatures[
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // keep-sorted start case=no
     &kIPHDesktopPWAsLinkCapturingLaunch,
     &kIPHDesktopPWAsLinkCapturingLaunchAppInTab,
@@ -386,7 +386,7 @@ const base::Feature* const kAllFeatures[
     &kIPHExtensionsPinnedByDefaultFeature,
 #endif  // BUILDFLAG(ENABLE_EXTENSIONS_CORE)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // keep-sorted start case=no
     &kIPHSignInBenefitsFeature,
     &kIPHSignInBenefitsNewSigninFeature,
