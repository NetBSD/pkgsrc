$NetBSD: patch-media_webrtc_helpers__unittests.cc,v 1.6 2025/09/08 13:24:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/webrtc/helpers_unittests.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ media/webrtc/helpers_unittests.cc
@@ -38,7 +38,7 @@ TEST(CreateWebRtcAudioProcessingModuleTe
   EXPECT_TRUE(config.echo_canceller.enabled);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   EXPECT_FALSE(config.gain_controller1.enabled);
   EXPECT_TRUE(config.gain_controller2.enabled);
 #elif BUILDFLAG(IS_CASTOS) || BUILDFLAG(IS_CAST_ANDROID)
@@ -65,7 +65,7 @@ TEST(CreateWebRtcAudioProcessingModuleTe
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 TEST(CreateWebRtcAudioProcessingModuleTest,
      InputVolumeAdjustmentEnabledWithAgc2) {
   ::base::test::ScopedFeatureList feature_list;
@@ -81,7 +81,7 @@ TEST(CreateWebRtcAudioProcessingModuleTe
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 TEST(CreateWebRtcAudioProcessingModuleTest,
      CanDisableInputVolumeAdjustmentWithAgc2) {
   ::base::test::ScopedFeatureList feature_list;
@@ -98,7 +98,7 @@ TEST(CreateWebRtcAudioProcessingModuleTe
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 TEST(CreateWebRtcAudioProcessingModuleTest,
      OnlyOneInputVolumeControllerEnabledOnDesktopPlatforms) {
   auto config = CreateApmGetConfig(
