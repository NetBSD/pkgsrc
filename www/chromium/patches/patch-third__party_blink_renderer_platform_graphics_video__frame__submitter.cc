$NetBSD: patch-third__party_blink_renderer_platform_graphics_video__frame__submitter.cc,v 1.13 2025/12/23 13:22:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/graphics/video_frame_submitter.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ third_party/blink/renderer/platform/graphics/video_frame_submitter.cc
@@ -380,7 +380,7 @@ void VideoFrameSubmitter::OnBeginFrame(
     auto& details = timing_details.find(frame_token)->value;
     auto& feedback = details.presentation_feedback;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // TODO: On Linux failure flag is unreliable, and perfectly rendered frames
     // are reported as failures all the time.
     bool presentation_failure = false;
