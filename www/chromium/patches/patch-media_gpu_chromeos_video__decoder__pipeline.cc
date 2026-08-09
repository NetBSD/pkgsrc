$NetBSD: patch-media_gpu_chromeos_video__decoder__pipeline.cc,v 1.24 2026/08/09 06:31:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/chromeos/video_decoder_pipeline.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ media/gpu/chromeos/video_decoder_pipeline.cc
@@ -682,7 +682,7 @@ void VideoDecoderPipeline::InitializeTas
           &OOPVideoDecoder::GetOriginalFrame,
           base::Unretained(static_cast<OOPVideoDecoder*>(decoder_.get())));
     } else {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
       if (!main_frame_pool_) {
         get_original_frame_cb = base::NullCallback();
       } else
@@ -1141,7 +1141,7 @@ VideoDecoderPipeline::PickDecoderOutputF
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_VAAPI)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_VAAPI)
   // Linux should always use a custom allocator (to allocate buffers using
   // libva) and a PlatformVideoFramePool.
   CHECK(allocator.has_value());
@@ -1150,7 +1150,7 @@ VideoDecoderPipeline::PickDecoderOutputF
   // VideoFrame::StorageType of VideoFrame::STORAGE_DMABUFS.
   main_frame_pool_->AsPlatformVideoFramePool()->SetCustomFrameAllocator(
       *allocator, VideoFrame::STORAGE_DMABUFS);
-#elif BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
   // Linux w/ V4L2 should not use a custom allocator
   // Only tested with video_decode_accelerator_tests
   // TODO(wenst@) Test with full Chromium Browser
@@ -1324,7 +1324,7 @@ VideoDecoderPipeline::PickDecoderOutputF
              << " VideoFrames";
     auxiliary_frame_pool_->set_parent_task_runner(decoder_task_runner_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // The custom allocator creates frames backed by NativePixmap, which uses a
     // VideoFrame::StorageType of VideoFrame::STORAGE_DMABUFS.
     auxiliary_frame_pool_->AsPlatformVideoFramePool()->SetCustomFrameAllocator(
