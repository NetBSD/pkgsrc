$NetBSD: patch-media_video_mappable__shared__image__video__frame__pool.cc,v 1.2 2026/04/10 17:31:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/video/mappable_shared_image_video_frame_pool.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ media/video/mappable_shared_image_video_frame_pool.cc
@@ -685,7 +685,7 @@ void MappableSharedImageVideoFramePool::
   }
 
   bool is_software_backed_video_frame = !video_frame->HasSharedImage();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
@@ -1093,7 +1093,7 @@ scoped_refptr<VideoFrame> MappableShared
       media::IOSurfaceIsWebGPUCompatible(handle.io_surface().get());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // TOOD(crbug.com/425634684): Check for webgpu support from
   // SharedImageCapabilities, once this metadata is compatible.
   is_webgpu_compatible =
