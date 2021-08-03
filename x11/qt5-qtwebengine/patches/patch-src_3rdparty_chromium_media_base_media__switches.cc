$NetBSD: patch-src_3rdparty_chromium_media_base_media__switches.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/media/base/media_switches.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/media/base/media_switches.cc
@@ -37,7 +37,7 @@ const char kDisableMediaSuspend[] = "dis
 const char kReportVp9AsAnUnsupportedMimeType[] =
     "report-vp9-as-an-unsupported-mime-type";
 
-#if defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_SOLARIS)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
 // The Alsa device to use when opening an audio input stream.
 const char kAlsaInputDevice[] = "alsa-input-device";
 // The Alsa device to use when opening an audio stream.
@@ -346,7 +346,7 @@ const base::Feature kGav1VideoDecoder{"G
 const base::Feature kGlobalMediaControls {
   "GlobalMediaControls",
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
