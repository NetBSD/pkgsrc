$NetBSD: patch-src_3rdparty_chromium_media_video_gpu__memory__buffer__video__frame__pool.cc,v 1.2 2026/04/30 06:39:41 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/media/video/gpu_memory_buffer_video_frame_pool.cc
@@ -651,7 +651,7 @@ void GpuMemoryBufferVideoFramePool::Pool
   }
 
   bool is_software_backed_video_frame = !video_frame->HasSharedImage();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
@@ -1052,7 +1052,7 @@ scoped_refptr<VideoFrame> GpuMemoryBuffe
       media::IOSurfaceIsWebGPUCompatible(handle.io_surface().get());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_webgpu_compatible =
       handle.type == gfx::NATIVE_PIXMAP &&
       handle.native_pixmap_handle().supports_zero_copy_webgpu_import;
@@ -1220,7 +1220,7 @@ GpuMemoryBufferVideoFramePool::PoolImpl:
       si_usage |= gpu::SHARED_IMAGE_USAGE_SCANOUT;
     }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/40194712): Always add the flag once the
     // OzoneImageBacking is by default turned on.
     if (base::CommandLine::ForCurrentProcess()->HasSwitch(
