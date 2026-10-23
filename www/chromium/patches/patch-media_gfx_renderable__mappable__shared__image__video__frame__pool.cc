$NetBSD: patch-media_gfx_renderable__mappable__shared__image__video__frame__pool.cc,v 1.1 2026/10/23 15:05:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gfx/renderable_mappable_shared_image_video_frame_pool.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ media/gfx/renderable_mappable_shared_image_video_frame_pool.cc
@@ -210,7 +210,7 @@ bool FrameResources::Initialize(VideoPix
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
   buffer_usage = gfx::BufferUsage::SCANOUT_VEA_CPU_READ;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, GBM_BO_USE_LINEAR (implied by SCANOUT_CPU_READ_WRITE) can
   // prevent GPU rendering on some drivers, notably NVIDIA's GBM driver,
   // because it disables GBM_BO_USE_RENDERING. Use SCANOUT instead if
