$NetBSD: patch-media_video_mappable__shared__image__video__frame__pool.cc,v 1.4 2026/05/10 15:30:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/video/mappable_shared_image_video_frame_pool.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ media/video/mappable_shared_image_video_frame_pool.cc
@@ -686,7 +686,7 @@ void MappableSharedImageVideoFramePool::
   }
 
   bool is_software_backed_video_frame = !video_frame->HasSharedImage();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
@@ -1099,7 +1099,7 @@ scoped_refptr<VideoFrame> MappableShared
           gpu::SHARED_IMAGE_USAGE_WEBGPU_READ);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Gate this on SharedImage usage as ScopedAccess now CHECKs for it.
   // TOOD(crbug.com/425634684, crbug.com/413659843): Check for webgpu support
   // from SharedImageCapabilities, once this metadata is compatible.
