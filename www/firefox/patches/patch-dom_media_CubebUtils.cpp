$NetBSD: patch-dom_media_CubebUtils.cpp,v 1.5 2020/01/18 15:32:40 nia Exp $

--- dom/media/CubebUtils.cpp.orig	Wed Jan  8 01:23:31 2020
+++ dom/media/CubebUtils.cpp
@@ -140,7 +140,7 @@ const char kBrandBundleURL[] = "chrome://branding/loca
 
 const char* AUDIOSTREAM_BACKEND_ID_STR[] = {
     "jack",  "pulse",       "alsa",  "audiounit", "audioqueue", "wasapi",
-    "winmm", "directsound", "sndio", "opensl",    "audiotrack", "kai"};
+    "winmm", "directsound", "sndio", "opensl",    "audiotrack", "kai", "sun"};
 /* Index for failures to create an audio stream the first time. */
 const int CUBEB_BACKEND_INIT_FAILURE_FIRST =
     ArrayLength(AUDIOSTREAM_BACKEND_ID_STR);
