$NetBSD: patch-remoting_codec_webrtc__video__encoder__vpx.cc,v 1.1 2025/02/06 09:58:17 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/codec/webrtc_video_encoder_vpx.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ remoting/codec/webrtc_video_encoder_vpx.cc
@@ -93,7 +93,7 @@ void SetVp8CodecParameters(vpx_codec_enc
                            const webrtc::DesktopSize& size) {
   SetCommonCodecParameters(config, size);
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (BUILDFLAG(IS_BSD) || BUILDFLAG(IS_LINUX)) && !BUILDFLAG(IS_CHROMEOS_LACROS)
   // On Linux, using too many threads for VP8 encoding has been linked to high
   // CPU usage on machines that are under stress. See http://crbug.com/1151148.
   // 5/3/2022 update: Perf testing has shown that doubling the number of threads
