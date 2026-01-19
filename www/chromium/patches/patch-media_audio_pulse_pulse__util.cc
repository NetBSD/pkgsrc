$NetBSD: patch-media_audio_pulse_pulse__util.cc,v 1.14 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/audio/pulse/pulse_util.cc.orig	2026-01-07 00:50:30.000000000 +0000
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
