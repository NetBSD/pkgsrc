$NetBSD: patch-chrome_browser_about__flags.cc,v 1.18 2026/04/21 15:21:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/about_flags.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/about_flags.cc
@@ -336,13 +336,13 @@
 #include "components/stylus_handwriting/win/features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/allocator/buildflags.h"
 #include "ui/ozone/public/ozone_switches.h"
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/data_protection/data_protection_features.h"
 #include "chrome/browser/enterprise/profile_management/profile_management_features.h"
 #include "chrome/browser/enterprise/webstore/features.h"
@@ -351,7 +351,7 @@
         // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/contextual_cueing/contextual_cueing_features.h"  // nogncheck
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
         // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
@@ -364,7 +364,7 @@
 #include "components/enterprise/platform_auth/platform_auth_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "components/enterprise/browser/reporting/reporting_features.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
@@ -830,6 +830,27 @@ const FeatureEntry::FeatureVariation
          "identity request to Android OS",
          kWebIdentityDigitalIdentityCredentialHighRiskDialogParam, nullptr}};
 
+#if BUILDFLAG(IS_BSD)
+const FeatureEntry::FeatureParam kAudioBackendPulseAudio[] = {
+        { "audio-backend", "pulseaudio" }};
+const FeatureEntry::FeatureParam kAudioBackendSndio[] = {
+        { "audio-backend", "sndio" }};
+const FeatureEntry::FeatureParam kAudioBackendAudioIO[] = {
+        { "audio-backend", "audioio" }};
+const FeatureEntry::FeatureParam kAudioBackendAlsa[] = {
+        { "audio-backend", "alsa" }};
+const FeatureEntry::FeatureVariation
+    kAudioBackendVariations[] = {
+        {"using PulseAudio by default if available",
+         kAudioBackendPulseAudio, nullptr},
+        {"using sndio by default if available",
+         kAudioBackendSndio, nullptr},
+        {"using audioio by default if available",
+         kAudioBackendAudioIO, nullptr},
+        {"using ALSA by default if available",
+         kAudioBackendAlsa, nullptr}};
+#endif
+
 const FeatureEntry::FeatureParam kMBIModeLegacy[] = {{"mode", "legacy"}};
 const FeatureEntry::FeatureParam kMBIModeEnabledPerRenderProcessHost[] = {
     {"mode", "per_render_process_host"}};
@@ -1241,7 +1262,7 @@ const FeatureEntry::FeatureVariation
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 // A limited number of combinations of the rich autocompletion params.
 const FeatureEntry::FeatureParam kOmniboxRichAutocompletionAggressive1[] = {
@@ -3442,7 +3463,7 @@ const FeatureEntry::FeatureVariation kAn
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOn[] =
     {{"link_capturing_state", "on_by_default"}};
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOff[] =
@@ -3468,7 +3489,7 @@ const flags_ui::FeatureEntry::FeatureVar
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const FeatureEntry::Choice kReplaceSyncPromosWithSignInPromosChoices[] = {
     {"Default", "", ""},
     {"Disabled", switches::kDisableFeatures,
@@ -3666,7 +3687,7 @@ const FeatureEntry::FeatureVariation kSe
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kContextualCueingEnabledNoEngagementCap[] = {
     {"BackoffTime", "0h"},
     {"BackoffMultiplierBase", "0.0"},
@@ -4428,7 +4449,7 @@ const FeatureEntry::FeatureVariation
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kNtpCustomizeChromeAutoOpenOnEveryNTP[] = {
     {"max_customize_chrome_auto_shown_count", "5"},
     {"max_customize_chrome_auto_shown_session_count", "5"}};
@@ -4506,7 +4527,7 @@ const FeatureEntry::FeatureVariation
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kProjectsPanelWithoutThreadsVariation[] = {
     {"include_threads_in_projects_panel", "false"}};
 const FeatureEntry::FeatureParam kProjectsPanelWithThreadsVariation[] = {
@@ -4542,7 +4563,7 @@ const FeatureEntry::FeatureVariation kSe
      kSeamlessSigninCompactSignin, nullptr}};
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kProfilePickerTextVariation1[] = {
     {"profile-picker-variation", "keep-work-and-life-separate"}};
 const FeatureEntry::FeatureParam kProfilePickerTextVariation2[] = {
@@ -4949,7 +4970,7 @@ const FeatureEntry kFeatureEntries[] = {
          kAutofillShowTypePredictionsVariations,
          "AutofillShowTypePredictions")},
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"autofill-at-memory", flag_descriptions::kAutofillAtMemoryName,
      flag_descriptions::kAutofillAtMemoryDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(autofill::features::kAutofillAtMemory)},
@@ -5608,7 +5629,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableIsolatedWebAppDevModeName,
      flag_descriptions::kEnableIsolatedWebAppDevModeDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kIsolatedWebAppDevMode)},
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-iwa-key-distribution-component",
      flag_descriptions::kEnableIwaKeyDistributionComponentName,
      flag_descriptions::kEnableIwaKeyDistributionComponentDescription,
@@ -5815,7 +5836,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kUseSCContentSharingPicker)},
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"pulseaudio-loopback-for-cast",
      flag_descriptions::kPulseaudioLoopbackForCastName,
      flag_descriptions::kPulseaudioLoopbackForCastDescription, kOsLinux,
@@ -5830,6 +5851,16 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kWaylandSessionManagementName,
      flag_descriptions::kWaylandSessionManagementDescription, kOsLinux,
      FEATURE_VALUE_TYPE(features::kWaylandSessionManagement)},
+
+#if BUILDFLAG(IS_BSD)
+    {"audio-backend",
+     flag_descriptions::kAudioBackendName,
+     flag_descriptions::kAudioBackendDescription, kOsLinux,
+     FEATURE_WITH_PARAMS_VALUE_TYPE(
+         media::kAudioBackend,
+         kAudioBackendVariations,
+         "AudioBackend")},
+#endif
 #endif  // BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(ENABLE_VR)
@@ -6312,7 +6343,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kFillOnAccountSelectDescription, kOsAll,
      FEATURE_VALUE_TYPE(password_manager::features::kFillOnAccountSelect)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"first-run-desktop-choice-screen-refresh",
      flag_descriptions::kFirstRunDesktopChoiceScreenRefreshName,
      flag_descriptions::kFirstRunDesktopChoiceScreenRefreshDescription,
@@ -6635,7 +6666,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "MlUrlScoring")},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"contextual-search-box-uses-contextual-search-provider",
      flag_descriptions::kContextualSearchBoxUsesContextualSearchProviderName,
      flag_descriptions::
@@ -7043,7 +7074,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     kNumSrpZpsRelatedSearches,
                                     "PowerTools")},
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"history-embeddings", flag_descriptions::kHistoryEmbeddingsName,
      flag_descriptions::kHistoryEmbeddingsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(history_embeddings::kHistoryEmbeddings)},
@@ -7222,7 +7253,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "NtpRealboxNext")},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"ntp-customize-chrome-auto-open",
      flag_descriptions::kNtpCustomizeChromeAutoOpenName,
      flag_descriptions::kNtpCustomizeChromeAutoOpenDescription, kOsDesktop,
@@ -7455,7 +7486,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(ENABLE_PRINTING)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"cups-ipp-printing-backend",
      flag_descriptions::kCupsIppPrintingBackendName,
      flag_descriptions::kCupsIppPrintingBackendDescription, kOsDesktop,
@@ -8294,7 +8325,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kGesturePropertiesDBusService)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-network-service-sandbox",
      flag_descriptions::kEnableNetworkServiceSandboxName,
      flag_descriptions::kEnableNetworkServiceSandboxDescription,
@@ -8797,7 +8828,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kGlobalVaapiLockDescription, kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(media::kGlobalVaapiLock)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -9252,7 +9283,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"auto-picture-in-picture-for-video-playback",
      flag_descriptions::kAutoPictureInPictureForVideoPlaybackName,
      flag_descriptions::kAutoPictureInPictureForVideoPlaybackDescription,
@@ -9429,7 +9460,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kReduceTransferSizeUpdatedIPCDescription, kOsAll,
      FEATURE_VALUE_TYPE(network::features::kReduceTransferSizeUpdatedIPC)},
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"reduce-user-agent-data-linux-platform-version",
      flag_descriptions::kReduceUserAgentDataLinuxPlatformVersionName,
      flag_descriptions::kReduceUserAgentDataLinuxPlatformVersionDescription,
@@ -9915,7 +9946,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kRcapsDynamicProfileCountryDescription, kOsAll,
      FEATURE_VALUE_TYPE(switches::kDynamicProfileCountry)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"enable-generic-oidc-auth-profile-management",
      flag_descriptions::kEnableGenericOidcAuthProfileManagementName,
      flag_descriptions::kEnableGenericOidcAuthProfileManagementDescription,
@@ -9925,7 +9956,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-user-navigation-capturing-pwa",
      flag_descriptions::kPwaNavigationCapturingName,
      flag_descriptions::kPwaNavigationCapturingDescription,
@@ -10317,7 +10348,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kResponsiveIframesDescription, kOsAll,
      FEATURE_VALUE_TYPE(blink::features::kResponsiveIframes)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"replace-sync-promos-with-sign-in-promos-desktop",
      flag_descriptions::kReplaceSyncPromosWithSignInPromosName,
      flag_descriptions::kReplaceSyncPromosWithSignInPromosDescription,
@@ -10690,7 +10721,7 @@ const FeatureEntry kFeatureEntries[] = {
          segmentation_platform::features::kSegmentationSurveyPage)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later",
      flag_descriptions::kAutofillEnableBuyNowPayLaterName,
      flag_descriptions::kAutofillEnableBuyNowPayLaterDescription,
@@ -10769,7 +10800,7 @@ const FeatureEntry kFeatureEntries[] = {
          password_manager::features::kPasswordFormClientsideClassifier)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"contextual-cueing", flag_descriptions::kContextualCueingName,
      flag_descriptions::kContextualCueingDescription, kOsDesktop | kOsAndroid,
      FEATURE_WITH_PARAMS_VALUE_TYPE(contextual_cueing::kContextualCueing,
@@ -11184,7 +11215,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ui::kUseNewEtc1Encoder)},
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"automatic-usb-detach", flag_descriptions::kAutomaticUsbDetachName,
      flag_descriptions::kAutomaticUsbDetachDescription, kOsAndroid | kOsLinux,
      FEATURE_VALUE_TYPE(features::kAutomaticUsbDetach)},
@@ -11215,7 +11246,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction",
      flag_descriptions::kAutofillEnableAmountExtractionName,
      flag_descriptions::kAutofillEnableAmountExtractionDescription,
@@ -11381,7 +11412,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          feature_engagement::kIPHAutofillCreditCardBenefitFeature)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"chrome-web-store-navigation-throttle",
      flag_descriptions::kChromeWebStoreNavigationThrottleName,
      flag_descriptions::kChromeWebStoreNavigationThrottleDescription,
@@ -11434,7 +11465,7 @@ const FeatureEntry kFeatureEntries[] = {
          supervised_user::kSupervisedUserUseUrlFilteringService)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction-testing",
      flag_descriptions::kAutofillEnableAmountExtractionTestingName,
      flag_descriptions::kAutofillEnableAmountExtractionTestingDescription,
@@ -11449,7 +11480,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableWebAppPredictableAppUpdatingDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kWebAppPredictableAppUpdating)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"root-scrollbar-follows-browser-theme",
      flag_descriptions::kRootScrollbarFollowsTheme,
      flag_descriptions::kRootScrollbarFollowsThemeDescription,
@@ -11702,7 +11733,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"tab-group-home", tabs::flag_descriptions::kTabGroupHomeName,
      tabs::flag_descriptions::kTabGroupHomeDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(tabs::kTabGroupHome)},
@@ -11765,7 +11796,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-site-search-allow-user-override-policy",
      flag_descriptions::kEnableSiteSearchAllowUserOverridePolicyName,
      flag_descriptions::kEnableSiteSearchAllowUserOverridePolicyDescription,
@@ -11856,7 +11887,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later-for-klarna",
      flag_descriptions::kAutofillEnableBuyNowPayLaterForKlarnaName,
      flag_descriptions::kAutofillEnableBuyNowPayLaterForKlarnaDescription,
@@ -11905,7 +11936,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later-for-externally-linked",
      flag_descriptions::kAutofillEnableBuyNowPayLaterForExternallyLinkedName,
      flag_descriptions::
@@ -12213,7 +12244,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // !BUILDFLAG(IS_ANDROID),
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-ntp-enterprise-shortcuts",
      flag_descriptions::kEnableNtpEnterpriseShortcutsName,
      flag_descriptions::kEnableNtpEnterpriseShortcutsDescription,
@@ -12321,7 +12352,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"contextual-suggestion-ui-improvements",
      flag_descriptions::kContextualSuggestionsUiImprovementsName,
      flag_descriptions::kContextualSuggestionsUiImprovementsDescription,
@@ -12413,7 +12444,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kCryptographyComplianceCnsa)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"lens-reinvocation-affordance",
      flag_descriptions::kLensSearchReinvocationAffordanceName,
      flag_descriptions::kLensSearchReinvocationAffordanceDescription,
@@ -12471,7 +12502,7 @@ const FeatureEntry kFeatureEntries[] = {
      STRING_VALUE_TYPE(variations::switches::kVariationsSeedCorpus, "")},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"passkey-unlock-manager", flag_descriptions::kPasskeyUnlockManagerName,
      flag_descriptions::kPasskeyUnlockManagerDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(device::kPasskeyUnlockManager)},
@@ -12512,7 +12543,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kUserValueDefaultBrowserStrings)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-read-aloud-ts-text-segmentation",
      flag_descriptions::kReadAnythingReadAloudTsTextSegmentationName,
      flag_descriptions::kReadAnythingReadAloudTsTextSegmentationDescription,
@@ -12524,7 +12555,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kHandleMdmErrorsForDasherAccountsDescription, kOsAll,
      FEATURE_VALUE_TYPE(switches::kHandleMdmErrorsForDasherAccounts)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"disable-u18-feedback-desktop",
      flag_descriptions::kDisableU18FeedbackDesktopName,
      flag_descriptions::kDisableU18FeedbackDesktopDescription,
@@ -12534,7 +12565,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "DisableU18FeedbackDesktop")},
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"profile-creation-decline-signin-cta-experiment",
      flag_descriptions::kProfileCreationDeclineSigninCTAExperimentName,
      flag_descriptions::kProfileCreationDeclineSigninCTAExperimentDescription,
@@ -12542,7 +12573,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(switches::kProfileCreationDeclineSigninCTAExperiment)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"profile-creation-friction-reduction-experiment-prefill-name-requirement",
      flag_descriptions::
          kProfileCreationFrictionReductionExperimentPrefillNameRequirementName,
@@ -12554,7 +12585,7 @@ const FeatureEntry kFeatureEntries[] = {
              kProfileCreationFrictionReductionExperimentPrefillNameRequirement)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"profile-creation-friction-reduction-experiment-remove-signin-step",
      flag_descriptions::
          kProfileCreationFrictionReductionExperimentRemoveSigninStepName,
@@ -12566,7 +12597,7 @@ const FeatureEntry kFeatureEntries[] = {
              kProfileCreationFrictionReductionExperimentRemoveSigninStep)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"profile-creation-friction-reduction-experiment-skip-customize-profile",
      flag_descriptions::
          kProfileCreationFrictionReductionExperimentSkipCustomizeProfileName,
@@ -12584,7 +12615,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(switches::kSearchSettingsUpdate)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"show-profile-picker-to-all-users-experiment",
      flag_descriptions::kShowProfilePickerToAllUsersExperimentName,
      flag_descriptions::kShowProfilePickerToAllUsersExperimentDescription,
@@ -12592,7 +12623,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(switches::kShowProfilePickerToAllUsersExperiment)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"open-all-profiles-from-profile-picker-experiment",
      flag_descriptions::kOpenAllProfilesFromProfilePickerExperimentName,
      flag_descriptions::kOpenAllProfilesFromProfilePickerExperimentDescription,
@@ -12607,7 +12638,7 @@ const FeatureEntry kFeatureEntries[] = {
          enterprise_signals::features::kProfileSignalsReportingEnabled)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"projects-panel", flag_descriptions::kProjectsPanelName,
      flag_descriptions::kProjectsPanelDescription, kOsDesktop,
      FEATURE_WITH_PARAMS_VALUE_TYPE(tab_groups::kProjectsPanel,
@@ -12651,7 +12682,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "AndroidDesktopZoomScaling")},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"profile-picker-text-variations",
      flag_descriptions::kProfilePickerTextVariationsName,
      flag_descriptions::kProfilePickerTextVariationsDescription,
@@ -12662,7 +12693,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"lens-overlay-optimization-filter",
      flag_descriptions::kLensOverlayOptimizationFilterName,
      flag_descriptions::kLensOverlayOptimizationFilterDescription, kOsDesktop,
@@ -12685,7 +12716,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(network::features::kConnectionAllowlists)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-with-readability-enabled",
      flag_descriptions::kReadAnythingWithReadabilityName,
      flag_descriptions::kReadAnythingWithReadabilityDescription, kOsDesktop,
@@ -12693,7 +12724,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-omnibox-chip",
      flag_descriptions::kReadAnythingOmniboxChipName,
      flag_descriptions::kReadAnythingOmniboxChipDescription, kOsDesktop,
@@ -12722,7 +12753,7 @@ const FeatureEntry kFeatureEntries[] = {
          autofill::features::kAutofillDisableBnplCountryCheckForTesting)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"infobar-prioritization", flag_descriptions::kInfobarPrioritizationName,
      flag_descriptions::kInfobarPrioritizationDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(infobars::features::kInfobarPrioritization)},
@@ -12740,7 +12771,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-immersive-reading-mode",
      flag_descriptions::kReadAnythingImmersiveReadingModeName,
      flag_descriptions::kReadAnythingImmersiveReadingModeDescription,
@@ -12753,7 +12784,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"lens-overlay-non-blocking-privacy-notice",
      flag_descriptions::kLensOverlayNonBlockingPrivacyNoticeName,
      flag_descriptions::kLensOverlayNonBlockingPrivacyNoticeDescription,
@@ -12818,7 +12849,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-your-saved-info-settings-page",
      flag_descriptions::kYourSavedInfoSettingsPageName,
      flag_descriptions::kYourSavedInfoSettingsPageDescription, kOsDesktop,
@@ -12915,14 +12946,14 @@ const FeatureEntry kFeatureEntries[] = {
          autofill::features::
              kAutofillAiBasedAmountExtractionIgnoreSeenTermsForTesting)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"updater-ui", flag_descriptions::kUpdaterUIName,
      flag_descriptions::kUpdaterUIDescription, kOsLinux | kOsMac | kOsWin,
      FEATURE_VALUE_TYPE(features::kUpdaterUI)},
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-line-focus", flag_descriptions::kReadAnythingLineFocusName,
      flag_descriptions::kReadAnythingLineFocusDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kReadAnythingLineFocus)},
@@ -12946,7 +12977,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(payments::android::kDeduplicateNativePaymentApps)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"password-upload-ui-update",
      flag_descriptions::kPasswordUploadUiUpdateName,
      flag_descriptions::kPasswordUploadUiUpdateDescription,
@@ -12983,7 +13014,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chrome::android::kAlwaysDrawCompositedToolbarHairline)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"saas-usage-reporting", flag_descriptions::kSaasUsageReportingName,
      flag_descriptions::kSaasUsageReportingDescription,
      kOsLinux | kOsMac | kOsWin,
