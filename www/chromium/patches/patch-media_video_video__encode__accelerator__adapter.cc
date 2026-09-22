$NetBSD: patch-media_video_video__encode__accelerator__adapter.cc,v 1.26 2026/09/22 13:41:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/video/video_encode_accelerator_adapter.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ media/video/video_encode_accelerator_adapter.cc
@@ -220,7 +220,7 @@ class VideoEncodeAcceleratorAdapter::Map
     DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
     DCHECK(gfx::Rect(coded_size_).Contains(gfx::Rect(visible_size)));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     const auto buffer_usage =
         gfx::BufferUsage::VEA_READ_CAMERA_AND_CPU_READ_WRITE;
 #else
@@ -546,7 +546,7 @@ void VideoEncodeAcceleratorAdapter::Init
 #endif  // BUILDFLAG(USE_PROPRIETARY_CODECS)
 
   auto storage_type = VideoEncodeAccelerator::Config::StorageType::kShmem;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Linux/ChromeOS require a special configuration to use dmabuf storage.
   // We need to keep sending frames with the same storage type.
   // Other platforms will happily mix GpuMemoryBuffer storage with shared-mem
