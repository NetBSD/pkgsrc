$NetBSD: patch-media_gfx_mappable__shared__image__video__frame__pool.cc,v 1.1 2026/10/23 15:05:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gfx/mappable_shared_image_video_frame_pool.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ media/gfx/mappable_shared_image_video_frame_pool.cc
@@ -684,7 +684,7 @@ void MappableSharedImageVideoFramePool::
   }
 
   bool is_software_backed_video_frame = !video_frame->HasSharedImage();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
