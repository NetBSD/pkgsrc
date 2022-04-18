$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_graphics_video__frame__submitter.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/platform/graphics/video_frame_submitter.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/graphics/video_frame_submitter.cc
@@ -192,7 +192,7 @@ void VideoFrameSubmitter::OnBeginFrame(
     if (viz::FrameTokenGT(pair.key, *next_frame_token_))
       continue;
     auto& feedback = pair.value.presentation_feedback;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // TODO: On Linux failure flag is unreliable, and perfectly rendered frames
     // are reported as failures all the time.
     bool presentation_failure = false;
