$NetBSD: patch-src_3rdparty_chromium_media_audio_audio__features.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/media/audio/audio_features.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/media/audio/audio_features.cc
@@ -12,7 +12,7 @@ namespace features {
 const base::Feature kAudioServiceOutOfProcessKillAtHang{
   "AudioServiceOutOfProcessKillAtHang",
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
