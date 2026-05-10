$NetBSD: patch-third__party_webrtc_modules_video__coding_codecs_av1_libaom__av1__encoder.cc,v 1.6 2026/05/10 15:30:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/modules/video_coding/codecs/av1/libaom_av1_encoder.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ third_party/webrtc/modules/video_coding/codecs/av1/libaom_av1_encoder.cc
@@ -67,6 +67,10 @@
 #define AOM_EFLAG_CALCULATE_PSNR (1 << 3)
 #endif
 
+#ifndef AOM_EFLAG_FREEZE_INTERNAL_STATE
+#define AOM_EFLAG_FREEZE_INTERNAL_STATE (1 << 2)
+#endif
+
 #if defined(WEBRTC_ENCODER_PSNR_STATS)
 constexpr bool kEnablePsnrStats = true;
 #else
