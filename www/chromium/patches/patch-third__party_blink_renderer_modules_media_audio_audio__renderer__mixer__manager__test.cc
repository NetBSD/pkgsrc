$NetBSD: patch-third__party_blink_renderer_modules_media_audio_audio__renderer__mixer__manager__test.cc,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/media/audio/audio_renderer_mixer_manager_test.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/modules/media/audio/audio_renderer_mixer_manager_test.cc
@@ -857,7 +857,7 @@ TEST_F(AudioRendererMixerManagerTest, Mi
             mixer->get_output_params_for_testing().sample_rate());
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_APPLE) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // Use 10 ms buffer (441 frames per buffer).
   EXPECT_EQ(output_sample_rate / 100,
             mixer->get_output_params_for_testing().frames_per_buffer());
