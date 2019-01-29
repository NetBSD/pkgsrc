$NetBSD: patch-dom_media_CubebUtils.cpp,v 1.3 2019/01/29 16:28:22 ryoon Exp $

--- dom/media/CubebUtils.cpp.orig	2019-01-18 00:20:24.000000000 +0000
+++ dom/media/CubebUtils.cpp
@@ -151,7 +151,7 @@ const char kBrandBundleURL[] = "chrome:/
 
 const char* AUDIOSTREAM_BACKEND_ID_STR[] = {
     "jack",  "pulse",       "alsa",  "audiounit", "audioqueue", "wasapi",
-    "winmm", "directsound", "sndio", "opensl",    "audiotrack", "kai"};
+    "winmm", "directsound", "sndio", "opensl",    "audiotrack", "kai", "oss"};
 /* Index for failures to create an audio stream the first time. */
 const int CUBEB_BACKEND_INIT_FAILURE_FIRST =
     ArrayLength(AUDIOSTREAM_BACKEND_ID_STR);
