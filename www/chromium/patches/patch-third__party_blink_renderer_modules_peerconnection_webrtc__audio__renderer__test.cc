$NetBSD: patch-third__party_blink_renderer_modules_peerconnection_webrtc__audio__renderer__test.cc,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/peerconnection/webrtc_audio_renderer_test.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/modules/peerconnection/webrtc_audio_renderer_test.cc
@@ -382,7 +382,7 @@ TEST_F(WebRtcAudioRendererTest, DISABLED
   SetupRenderer(kDefaultOutputDeviceId);
   renderer_proxy_->Start();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_APPLE) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   static const int kExpectedBufferSize = kHardwareSampleRate / 100;
 #elif BUILDFLAG(IS_ANDROID)
   static const int kExpectedBufferSize = 2 * kHardwareSampleRate / 100;
