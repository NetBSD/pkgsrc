$NetBSD: patch-components_viz_service_frame__sinks_video__capture_frame__sink__video__capturer__impl.cc,v 1.3 2026/11/19 19:46:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/frame_sinks/video_capture/frame_sink_video_capturer_impl.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/viz/service/frame_sinks/video_capture/frame_sink_video_capturer_impl.cc
@@ -1161,7 +1161,7 @@ void FrameSinkVideoCapturerImpl::MaybeCa
   const bool prefer_mappable_shared_image =
       buffer_format_preference_ ==
       mojom::BufferFormatPreference::kPreferMappableSharedImage;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool prefer_shared_image =
       prefer_mappable_shared_image ||
       buffer_format_preference_ ==
@@ -1403,7 +1403,7 @@ void FrameSinkVideoCapturerImpl::DidCopy
         frame_capture.CaptureFailed(CaptureResult::kARGBReadbackFailed);
       }
     } else {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       CHECK(buffer_format_preference_ ==
                 mojom::BufferFormatPreference::kPreferMappableSharedImage ||
             buffer_format_preference_ ==
