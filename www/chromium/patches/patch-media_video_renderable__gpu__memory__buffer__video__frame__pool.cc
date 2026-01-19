$NetBSD: patch-media_video_renderable__gpu__memory__buffer__video__frame__pool.cc,v 1.7 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/video/renderable_gpu_memory_buffer_video_frame_pool.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ media/video/renderable_gpu_memory_buffer_video_frame_pool.cc
@@ -196,7 +196,7 @@ bool FrameResources::Initialize(VideoPix
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
   buffer_usage = gfx::BufferUsage::SCANOUT_VEA_CPU_READ;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, GBM_BO_USE_LINEAR (implied by SCANOUT_CPU_READ_WRITE) can
   // prevent GPU rendering on some drivers, notably NVIDIA's GBM driver,
   // because it disables GBM_BO_USE_RENDERING. Use SCANOUT instead if
