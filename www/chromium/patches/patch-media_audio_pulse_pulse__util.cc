$NetBSD: patch-media_audio_pulse_pulse__util.cc,v 1.19 2026/05/10 15:29:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/audio/pulse/pulse_util.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ media/audio/pulse/pulse_util.cc
@@ -45,8 +45,12 @@ constexpr char kBrowserDisplayName[] = "
 
 #if defined(DLOPEN_PULSEAUDIO)
 static const base::FilePath::CharType kPulseLib[] =
+#if BUILDFLAG(IS_BSD)
+    FILE_PATH_LITERAL("libpulse.so");
+#else
     FILE_PATH_LITERAL("libpulse.so.0");
 #endif
+#endif
 
 void DestroyMainloop(pa_threaded_mainloop* mainloop) {
   pa_threaded_mainloop_stop(mainloop);
