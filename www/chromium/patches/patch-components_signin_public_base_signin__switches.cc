$NetBSD: patch-components_signin_public_base_signin__switches.cc,v 1.14 2026/02/15 09:04:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/signin/public/base/signin_switches.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ components/signin/public/base/signin_switches.cc
@@ -107,7 +107,7 @@ BASE_FEATURE(kChromeAndroidIdentitySurve
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kChromeIdentitySurveyAddressBubbleSignin,
              base::FEATURE_ENABLED_BY_DEFAULT);
 BASE_FEATURE(kChromeIdentitySurveyDiceWebSigninAccepted,
@@ -134,7 +134,7 @@ BASE_FEATURE(kChromeIdentitySurveySwitch
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kChromeIdentitySurveyLaunchWithDelay,
              base::FEATURE_ENABLED_BY_DEFAULT);
 BASE_FEATURE_PARAM(base::TimeDelta,
@@ -343,7 +343,7 @@ BASE_FEATURE_PARAM(base::TimeDelta,
                    base::Days(7));
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kOpenAllProfilesFromProfilePickerExperiment,
              base::FEATURE_DISABLED_BY_DEFAULT);
 const base::FeatureParam<int>
@@ -352,7 +352,7 @@ const base::FeatureParam<int>
         "max_profiles_count_to_show_open_all_button_in_profile_picker", 5};
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kProfileCreationDeclineSigninCTAExperiment,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
@@ -395,7 +395,7 @@ BASE_FEATURE(kRestrictDeviceManagementSe
 BASE_FEATURE(kRollbackDiceMigration, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kShowProfilePickerToAllUsersExperiment,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -410,7 +410,7 @@ const base::FeatureParam<int> kContextua
     "contextual_signin_promo_dismissed_threshold",
     2);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSignInPromoMaterialNextUI, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
