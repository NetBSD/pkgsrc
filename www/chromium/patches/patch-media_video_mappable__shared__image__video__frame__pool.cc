$NetBSD: patch-media_video_mappable__shared__image__video__frame__pool.cc,v 1.14 2026/10/13 13:16:44 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/video/mappable_shared_image_video_frame_pool.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ media/video/mappable_shared_image_video_frame_pool.cc
@@ -684,7 +684,7 @@ void MappableSharedImageVideoFramePool::
   }
 
   bool is_software_backed_video_frame = !video_frame->HasSharedImage();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
