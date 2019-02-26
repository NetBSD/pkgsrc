$NetBSD: patch-dom_media_CubebUtils.cpp,v 1.2 2019/02/26 11:23:53 ryoon Exp $

--- dom/media/CubebUtils.cpp.orig	2019-02-13 14:19:37.000000000 +0000
+++ dom/media/CubebUtils.cpp
@@ -143,7 +143,7 @@ const char kBrandBundleURL[] = "chrome:/
 
 const char* AUDIOSTREAM_BACKEND_ID_STR[] = {
     "jack",  "pulse",       "alsa",  "audiounit", "audioqueue", "wasapi",
-    "winmm", "directsound", "sndio", "opensl",    "audiotrack", "kai"};
+    "winmm", "directsound", "sndio", "opensl",    "audiotrack", "kai", "oss"};
 /* Index for failures to create an audio stream the first time. */
 const int CUBEB_BACKEND_INIT_FAILURE_FIRST =
     ArrayLength(AUDIOSTREAM_BACKEND_ID_STR);
