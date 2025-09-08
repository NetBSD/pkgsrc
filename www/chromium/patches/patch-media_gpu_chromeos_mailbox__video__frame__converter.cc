$NetBSD: patch-media_gpu_chromeos_mailbox__video__frame__converter.cc,v 1.6 2025/09/08 13:24:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/chromeos/mailbox_video_frame_converter.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ media/gpu/chromeos/mailbox_video_frame_converter.cc
@@ -321,7 +321,7 @@ bool MailboxVideoFrameConverter::Generat
                            VideoPixelFormatToString(origin_frame->format()));
     return false;
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If format is true multiplanar format, we prefer external sampler on
   // ChromeOS and Linux.
   if (si_format->is_multi_plane()) {
