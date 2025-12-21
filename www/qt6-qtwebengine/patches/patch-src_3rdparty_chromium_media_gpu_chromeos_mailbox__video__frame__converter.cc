$NetBSD: patch-src_3rdparty_chromium_media_gpu_chromeos_mailbox__video__frame__converter.cc,v 1.1 2025/12/21 09:38:32 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/gpu/chromeos/mailbox_video_frame_converter.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/media/gpu/chromeos/mailbox_video_frame_converter.cc
@@ -67,7 +67,7 @@ viz::SharedImageFormat GetSharedImageFor
                     << static_cast<int>(buffer_format);
       NOTREACHED();
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If format is true multiplanar format, we prefer external sampler on
   // ChromeOS and Linux.
   if (format.is_multi_plane()) {
