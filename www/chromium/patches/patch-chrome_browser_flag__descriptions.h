$NetBSD: patch-chrome_browser_flag__descriptions.h,v 1.3 2025/07/07 09:23:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/flag_descriptions.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/flag_descriptions.h
@@ -413,7 +413,7 @@ extern const char
     kAutofillEnableAllowlistForBmoCardCategoryBenefitsDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kAutofillEnableAmountExtractionAllowlistDesktopName[];
 extern const char kAutofillEnableAmountExtractionAllowlistDesktopDescription[];
 extern const char kAutofillEnableAmountExtractionDesktopName[];
@@ -424,7 +424,7 @@ extern const char kAutofillEnableAmountE
         // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kAutofillEnableBuyNowPayLaterName[];
 extern const char kAutofillEnableBuyNowPayLaterDescription[];
 
@@ -656,7 +656,7 @@ extern const char kContextMenuEmptySpace
 extern const char kContextMenuEmptySpaceDescription[];
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kContextualCueingName[];
 extern const char kContextualCueingDescription[];
 extern const char kGlicZeroStateSuggestionsName[];
@@ -847,7 +847,7 @@ extern const char kDevicePostureName[];
 extern const char kDevicePostureDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kDocumentPictureInPictureAnimateResizeName[];
 extern const char kDocumentPictureInPictureAnimateResizeDescription[];
 
@@ -1006,7 +1006,7 @@ extern const char kEnableIsolatedWebAppA
 extern const char kEnableIsolatedWebAppDevModeName[];
 extern const char kEnableIsolatedWebAppDevModeDescription[];
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kEnableIwaKeyDistributionComponentName[];
 extern const char kEnableIwaKeyDistributionComponentDescription[];
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -2079,7 +2079,7 @@ extern const char kRetainOmniboxOnFocusN
 extern const char kRetainOmniboxOnFocusDescription[];
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kRootScrollbarFollowsTheme[];
 extern const char kRootScrollbarFollowsThemeDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
@@ -2226,7 +2226,7 @@ extern const char kDefaultSiteInstanceGr
 extern const char kDefaultSiteInstanceGroupsDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kPwaNavigationCapturingName[];
 extern const char kPwaNavigationCapturingDescription[];
 #endif
@@ -2386,7 +2386,7 @@ extern const char kTouchTextEditingRedes
 extern const char kTranslateForceTriggerOnEnglishName[];
 extern const char kTranslateForceTriggerOnEnglishDescription[];
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kEnableHistorySyncOptinName[];
 extern const char kEnableHistorySyncOptinDescription[];
 
@@ -2641,7 +2641,7 @@ extern const char kReduceAcceptLanguageD
 extern const char kReduceTransferSizeUpdatedIPCName[];
 extern const char kReduceTransferSizeUpdatedIPCDescription[];
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kReduceUserAgentDataLinuxPlatformVersionName[];
 extern const char kReduceUserAgentDataLinuxPlatformVersionDescription[];
 #endif  // #if BUILDFLAG(IS_LINUX)
@@ -3430,7 +3430,7 @@ extern const char kTranslateOpenSettings
 extern const char kTranslateOpenSettingsDescription[];
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kWasmTtsComponentUpdaterEnabledName[];
 extern const char kWasmTtsComponentUpdaterEnabledDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
@@ -4630,7 +4630,7 @@ extern const char kTetheringExperimental
 
 #endif  // #if BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kGetAllScreensMediaName[];
 extern const char kGetAllScreensMediaDescription[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -4765,7 +4765,7 @@ extern const char kEnableArmHwdrmDescrip
 
 // Linux ---------------------------------------------------------------------
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kOzonePlatformHintChoiceDefault[];
 extern const char kOzonePlatformHintChoiceAuto[];
 extern const char kOzonePlatformHintChoiceX11[];
@@ -4796,6 +4796,9 @@ extern const char kWaylandTextInputV3Des
 
 extern const char kWaylandUiScalingName[];
 extern const char kWaylandUiScalingDescription[];
+
+extern const char kAudioBackendName[];
+extern const char kAudioBackendDescription[];
 #endif  // BUILDFLAG(IS_LINUX)
 
 // Random platform combinations -----------------------------------------------
@@ -4810,7 +4813,7 @@ extern const char kWebBluetoothConfirmPa
 extern const char kWebBluetoothConfirmPairingSupportDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(ENABLE_PRINTING)
 extern const char kCupsIppPrintingBackendName[];
 extern const char kCupsIppPrintingBackendDescription[];
@@ -4823,7 +4826,7 @@ extern const char kScreenlockReauthCardD
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kFollowingFeedSidepanelName[];
 extern const char kFollowingFeedSidepanelDescription[];
 
@@ -4840,7 +4843,7 @@ extern const char kTaskManagerDesktopRef
 extern const char kTaskManagerDesktopRefreshDescription[];
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kEnableNetworkServiceSandboxName[];
 extern const char kEnableNetworkServiceSandboxDescription[];
 
@@ -4932,7 +4935,7 @@ extern const char kElementCaptureName[];
 extern const char kElementCaptureDescription[];
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kUIDebugToolsName[];
 extern const char kUIDebugToolsDescription[];
 #endif
@@ -4971,7 +4974,7 @@ extern const char kComposeUpfrontInputMo
 extern const char kComposeUpfrontInputModesDescription[];
 #endif  // BUILDFLAG(ENABLE_COMPOSE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kThirdPartyProfileManagementName[];
 extern const char kThirdPartyProfileManagementDescription[];
 
@@ -5045,7 +5048,7 @@ extern const char kEnablePolicyPromotion
 extern const char kSupervisedUserBlockInterstitialV3Name[];
 extern const char kSupervisedUserBlockInterstitialV3Description[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kSupervisedProfileHideGuestName[];
 extern const char kSupervisedProfileHideGuestDescription[];
 
