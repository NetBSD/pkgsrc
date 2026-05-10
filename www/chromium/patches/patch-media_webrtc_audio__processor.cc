$NetBSD: patch-media_webrtc_audio__processor.cc,v 1.19 2026/05/10 15:30:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/webrtc/audio_processor.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ media/webrtc/audio_processor.cc
@@ -518,7 +518,7 @@ std::optional<double> AudioProcessor::Pr
   // controller.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
   DCHECK_LE(volume, 1.0);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // We have a special situation on Linux where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
