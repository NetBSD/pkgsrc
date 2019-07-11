$NetBSD: patch-dom_media_CubebUtils.cpp,v 1.4 2019/07/11 11:32:40 ryoon Exp $

--- dom/media/CubebUtils.cpp.orig	2019-07-06 01:48:31.000000000 +0000
+++ dom/media/CubebUtils.cpp
@@ -163,7 +163,7 @@ const char kBrandBundleURL[] = "chrome:/
 
 const char* AUDIOSTREAM_BACKEND_ID_STR[] = {
     "jack",  "pulse",       "alsa",  "audiounit", "audioqueue", "wasapi",
-    "winmm", "directsound", "sndio", "opensl",    "audiotrack", "kai"};
+    "winmm", "directsound", "sndio", "opensl",    "audiotrack", "kai", "oss", "sun"};
 /* Index for failures to create an audio stream the first time. */
 const int CUBEB_BACKEND_INIT_FAILURE_FIRST =
     ArrayLength(AUDIOSTREAM_BACKEND_ID_STR);
