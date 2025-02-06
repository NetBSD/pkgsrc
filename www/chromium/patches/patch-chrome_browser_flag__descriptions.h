$NetBSD: patch-chrome_browser_flag__descriptions.h,v 1.1 2025/02/06 09:57:48 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/flag_descriptions.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/flag_descriptions.h
@@ -293,7 +293,7 @@ extern const char kImprovedSigninUIOnDes
 extern const char kImprovedSigninUIOnDesktopDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kAutofillEnableAmountExtractionDesktopName[];
 extern const char kAutofillEnableAmountExtractionDesktopDescription[];
 #endif
@@ -302,7 +302,7 @@ extern const char kAutofillEnableAndroid
 extern const char kAutofillEnableAndroidNKeyForFidoAuthenticationDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kAutofillEnableBuyNowPayLaterForAffirmName[];
 extern const char kAutofillEnableBuyNowPayLaterForAffirmDescription[];
 
@@ -737,7 +737,7 @@ extern const char kDevicePostureName[];
 extern const char kDevicePostureDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kDocumentPictureInPictureAnimateResizeName[];
 extern const char kDocumentPictureInPictureAnimateResizeDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
@@ -1998,7 +1998,7 @@ extern const char kShowAutofillTypePredi
 extern const char kShowAutofillTypePredictionsDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kShowFeaturedEnterpriseSiteSearchName[];
 extern const char kShowFeaturedEnterpriseSiteSearchDescription[];
 
@@ -2020,7 +2020,7 @@ extern const char kSiteInstanceGroupsFor
 extern const char kSiteInstanceGroupsForDataUrlsDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kSiteSearchSettingsPolicyName[];
 extern const char kSiteSearchSettingsPolicyDescription[];
 
@@ -2182,7 +2182,7 @@ extern const char kTouchTextEditingRedes
 extern const char kTranslateForceTriggerOnEnglishName[];
 extern const char kTranslateForceTriggerOnEnglishDescription[];
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kTranslationAPIName[];
 extern const char kTranslationAPIDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -4514,7 +4514,7 @@ extern const char kBlinkExtensionDiagnos
 extern const char kBlinkExtensionDiagnosticsDescription[];
 #endif  // #if BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kGetAllScreensMediaName[];
 extern const char kGetAllScreensMediaDescription[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -4652,7 +4652,7 @@ extern const char kEnableArmHwdrmDescrip
 
 // Linux ---------------------------------------------------------------------
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kOzonePlatformHintChoiceDefault[];
 extern const char kOzonePlatformHintChoiceAuto[];
 extern const char kOzonePlatformHintChoiceX11[];
@@ -4677,6 +4677,9 @@ extern const char kWaylandTextInputV3Des
 
 extern const char kWaylandUiScalingName[];
 extern const char kWaylandUiScalingDescription[];
+
+extern const char kAudioBackendName[];
+extern const char kAudioBackendDescription[];
 #endif  // BUILDFLAG(IS_LINUX)
 
 // Random platform combinations -----------------------------------------------
@@ -4696,7 +4699,7 @@ extern const char kWebBluetoothConfirmPa
 extern const char kWebBluetoothConfirmPairingSupportDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kSkipUndecryptablePasswordsName[];
 extern const char kSkipUndecryptablePasswordsDescription[];
 
@@ -4718,7 +4721,7 @@ extern const char kScreenlockReauthPromo
         // BUILDFLAG(IS_CHROMEOS_ASH)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kFollowingFeedSidepanelName[];
 extern const char kFollowingFeedSidepanelDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
@@ -4732,7 +4735,7 @@ extern const char kTaskManagerDesktopRef
 extern const char kTaskManagerDesktopRefreshDescription[];
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kEnableNetworkServiceSandboxName[];
 extern const char kEnableNetworkServiceSandboxDescription[];
 
@@ -4829,7 +4832,7 @@ extern const char kElementCaptureDescrip
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kUIDebugToolsName[];
 extern const char kUIDebugToolsDescription[];
 #endif
@@ -4880,7 +4883,7 @@ extern const char kComposeUpfrontInputMo
 extern const char kComposeUpfrontInputModesDescription[];
 #endif  // BUILDFLAG(ENABLE_COMPOSE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kThirdPartyProfileManagementName[];
 extern const char kThirdPartyProfileManagementDescription[];
 
@@ -4946,7 +4949,7 @@ extern const char kOverlayScrollbarsOSSe
 extern const char kOverlayScrollbarsOSSettingsDescription[];
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kSupervisedProfileHideGuestName[];
 extern const char kSupervisedProfileHideGuestDescription[];
 
