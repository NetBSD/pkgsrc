$NetBSD: patch-media_webrtc_trunk_webrtc_modules_video__coding_main_source_receiver.cc,v 1.1 2015/02/28 04:30:55 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/video_coding/main/source/receiver.cc.orig	2015-02-17 21:40:45.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/video_coding/main/source/receiver.cc
@@ -159,12 +159,13 @@ VCMEncodedFrame* VCMReceiver::FrameForDe
   // Assume that render timing errors are due to changes in the video stream.
   if (next_render_time_ms < 0) {
     timing_error = true;
-  } else if (std::abs(next_render_time_ms - now_ms) > max_video_delay_ms_) {
+  } else if (std::abs(static_cast<int>(next_render_time_ms - now_ms)) >
+             max_video_delay_ms_) {
     WEBRTC_TRACE(webrtc::kTraceWarning, webrtc::kTraceVideoCoding,
                  VCMId(vcm_id_, receiver_id_),
                  "This frame is out of our delay bounds, resetting jitter "
                  "buffer: %d > %d",
-                 static_cast<int>(std::abs(next_render_time_ms - now_ms)),
+                 std::abs(static_cast<int>(next_render_time_ms - now_ms)),
                  max_video_delay_ms_);
     timing_error = true;
   } else if (static_cast<int>(timing_->TargetVideoDelay()) >
