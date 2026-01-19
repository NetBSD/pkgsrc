$NetBSD: patch-media_gpu_chromeos_mailbox__video__frame__converter.cc,v 1.14 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/chromeos/mailbox_video_frame_converter.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ media/gpu/chromeos/mailbox_video_frame_converter.cc
@@ -226,7 +226,7 @@ MailboxVideoFrameConverter::GenerateShar
                            VideoPixelFormatToString(origin_frame->format()));
     return nullptr;
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If format is true multiplanar format, we prefer external sampler on
   // ChromeOS and Linux.
   if (si_format->is_multi_plane()) {
