$NetBSD: patch-media_gpu_chromeos_video__decoder__pipeline.cc,v 1.1 2025/02/06 09:58:13 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/chromeos/video_decoder_pipeline.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/gpu/chromeos/video_decoder_pipeline.cc
@@ -1095,7 +1095,7 @@ VideoDecoderPipeline::PickDecoderOutputF
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_VAAPI)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_VAAPI)
   // Linux should always use a custom allocator (to allocate buffers using
   // libva) and a PlatformVideoFramePool.
   CHECK(allocator.has_value());
@@ -1104,7 +1104,7 @@ VideoDecoderPipeline::PickDecoderOutputF
   // VideoFrame::StorageType of VideoFrame::STORAGE_DMABUFS.
   main_frame_pool_->AsPlatformVideoFramePool()->SetCustomFrameAllocator(
       *allocator, VideoFrame::STORAGE_DMABUFS);
-#elif BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
   // Linux w/ V4L2 should not use a custom allocator
   // Only tested with video_decode_accelerator_tests
   // TODO(wenst@) Test with full Chromium Browser
@@ -1286,7 +1286,7 @@ VideoDecoderPipeline::PickDecoderOutputF
              << " VideoFrames";
     auxiliary_frame_pool_->set_parent_task_runner(decoder_task_runner_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // The custom allocator creates frames backed by NativePixmap, which uses a
     // VideoFrame::StorageType of VideoFrame::STORAGE_DMABUFS.
     auxiliary_frame_pool_->AsPlatformVideoFramePool()->SetCustomFrameAllocator(
