$NetBSD: patch-third__party_blink_renderer_platform_graphics_video__frame__submitter.cc,v 1.25 2026/09/02 13:13:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/graphics/video_frame_submitter.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/blink/renderer/platform/graphics/video_frame_submitter.cc
@@ -410,7 +410,7 @@ void VideoFrameSubmitter::OnBeginFrame(
     auto& details = timing_details.find(frame_token)->value;
     auto& feedback = details.presentation_feedback;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // TODO: On Linux failure flag is unreliable, and perfectly rendered frames
     // are reported as failures all the time.
     bool presentation_failure = false;
