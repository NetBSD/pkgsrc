$NetBSD: patch-media_video_gpu__memory__buffer__video__frame__pool.cc,v 1.8 2025/10/16 19:43:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ media/video/gpu_memory_buffer_video_frame_pool.cc
@@ -679,7 +679,7 @@ void GpuMemoryBufferVideoFramePool::Pool
   }
 
   bool is_software_backed_video_frame = !video_frame->HasSharedImage();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
@@ -1080,7 +1080,7 @@ scoped_refptr<VideoFrame> GpuMemoryBuffe
       media::IOSurfaceIsWebGPUCompatible(handle.io_surface().get());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_webgpu_compatible =
       handle.type == gfx::NATIVE_PIXMAP &&
       handle.native_pixmap_handle().supports_zero_copy_webgpu_import;
@@ -1248,7 +1248,7 @@ GpuMemoryBufferVideoFramePool::PoolImpl:
       si_usage |= gpu::SHARED_IMAGE_USAGE_SCANOUT;
     }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/40194712): Always add the flag once the
     // OzoneImageBacking is by default turned on.
     if (base::CommandLine::ForCurrentProcess()->HasSwitch(
