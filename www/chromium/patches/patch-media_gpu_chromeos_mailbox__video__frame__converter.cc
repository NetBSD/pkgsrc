$NetBSD: patch-media_gpu_chromeos_mailbox__video__frame__converter.cc,v 1.5 2025/08/13 07:44:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/chromeos/mailbox_video_frame_converter.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ media/gpu/chromeos/mailbox_video_frame_converter.cc
@@ -68,7 +68,7 @@ viz::SharedImageFormat GetSharedImageFor
                     << static_cast<int>(buffer_format);
       NOTREACHED();
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If format is true multiplanar format, we prefer external sampler on
   // ChromeOS and Linux.
   if (format.is_multi_plane()) {
