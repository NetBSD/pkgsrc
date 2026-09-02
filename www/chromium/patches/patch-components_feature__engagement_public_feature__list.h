$NetBSD: patch-components_feature__engagement_public_feature__list.h,v 1.25 2026/09/02 13:13:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/feature_engagement/public/feature_list.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/feature_engagement/public/feature_list.h
@@ -402,7 +402,7 @@ DEFINE_VARIATION_PARAM(kIPHiOSPinMostVis
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 DEFINE_VARIATION_PARAM(kEsbDownloadRowPromoFeature, "EsbDownloadRowPromo");
 #endif
@@ -552,7 +552,7 @@ DEFINE_VARIATION_PARAM(kIPHTabGroupsShar
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHAutofillAccountNameEmailSuggestionFeature,
                        "IPH_AutofillAccountNameEmailSuggestion");
 DEFINE_VARIATION_PARAM(kIPHAutofillAiOptInFeature, "IPH_AutofillAiOptIn");
@@ -597,7 +597,7 @@ DEFINE_VARIATION_PARAM(kIPHLauncherSearc
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHDesktopPWAsLinkCapturingLaunch,
                        "IPH_DesktopPWAsLinkCapturingLaunch");
 DEFINE_VARIATION_PARAM(kIPHDesktopPWAsLinkCapturingLaunchAppInTab,
@@ -605,7 +605,7 @@ DEFINE_VARIATION_PARAM(kIPHDesktopPWAsLi
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHSignInBenefitsFeature, "IPH_SignInBenefits");
 DEFINE_VARIATION_PARAM(kIPHSupervisedUserProfileSigninFeature,
                        "IPH_SupervisedUserProfileSignin");
@@ -845,7 +845,7 @@ inline constexpr flags_ui::FeatureEntry:
         VARIATION_ENTRY(kIPHWhatsNewUpdatedFeature),
 // keep-sorted end
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(ENABLE_EXTENSIONS)
         VARIATION_ENTRY(kIPHExtensionsMenuFeature),
         VARIATION_ENTRY(kIPHExtensionsRequestAccessButtonFeature),
@@ -922,7 +922,7 @@ inline constexpr flags_ui::FeatureEntry:
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // keep-sorted start case=no
         VARIATION_ENTRY(kIPHAutofillAccountNameEmailSuggestionFeature),
         VARIATION_ENTRY(kIPHAutofillAiOptInFeature),
@@ -950,13 +950,13 @@ inline constexpr flags_ui::FeatureEntry:
         VARIATION_ENTRY(kIPHLauncherSearchHelpUiFeature),
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         VARIATION_ENTRY(kIPHDesktopPWAsLinkCapturingLaunch),
         VARIATION_ENTRY(kIPHDesktopPWAsLinkCapturingLaunchAppInTab),
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         VARIATION_ENTRY(kIPHSignInBenefitsFeature),
         VARIATION_ENTRY(kIPHSupervisedUserProfileSigninFeature),
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
