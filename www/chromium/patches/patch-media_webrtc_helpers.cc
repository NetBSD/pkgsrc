$NetBSD: patch-media_webrtc_helpers.cc,v 1.14 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/webrtc/helpers.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ media/webrtc/helpers.cc
@@ -48,14 +48,14 @@ void ConfigAutomaticGainControl(const Au
     return;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool kInputVolumeAdjustmentOverrideAllowed = true;
 #elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
   const bool kInputVolumeAdjustmentOverrideAllowed = false;
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // Use AGC2 digital and input volume controller.
   // TODO(crbug.com/40872787): Remove `kWebRtcAllowInputVolumeAdjustment` safely
   // and set `input_volume_controller.enabled` true.
