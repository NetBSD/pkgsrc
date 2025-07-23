$NetBSD: patch-third__party_libwebrtc_modules_video__capture_video__capture__options.cc,v 1.2 2025/07/23 13:57:35 ryoon Exp $

--- third_party/libwebrtc/modules/video_capture/video_capture_options.cc.orig	2025-05-21 12:41:53.782245708 +0000
+++ third_party/libwebrtc/modules/video_capture/video_capture_options.cc
@@ -37,7 +37,7 @@ void VideoCaptureOptions::Init(Callback*
     return;
   }
 #endif
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
   if (!allow_v4l2_)
     callback->OnInitialized(Status::UNAVAILABLE);
   else
