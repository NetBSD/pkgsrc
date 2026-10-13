$NetBSD: patch-media_gpu_chromeos_video__decoder__pipeline.cc,v 1.29 2026/10/13 13:16:43 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/chromeos/video_decoder_pipeline.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ media/gpu/chromeos/video_decoder_pipeline.cc
@@ -720,7 +720,7 @@ void VideoDecoderPipeline::InitializeTas
       NOTREACHED();
 #endif  // BUILDFLAG(ENABLE_OOP_VIDEO_DECODER)
     } else {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
       if (!main_frame_pool_) {
         get_original_frame_cb = base::NullCallback();
       } else
@@ -1179,7 +1179,7 @@ VideoDecoderPipeline::PickDecoderOutputF
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Linux: behavior depends on which backend the decoder represents, signaled
   // by whether it supplied a custom allocator.
   if (allocator.has_value()) {
@@ -1373,7 +1373,7 @@ VideoDecoderPipeline::PickDecoderOutputF
              << " VideoFrames";
     auxiliary_frame_pool_->set_parent_task_runner(decoder_task_runner_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // The custom allocator creates frames backed by NativePixmap, which uses a
     // VideoFrame::StorageType of VideoFrame::STORAGE_DMABUFS.
     auxiliary_frame_pool_->AsPlatformVideoFramePool()->SetCustomFrameAllocator(
