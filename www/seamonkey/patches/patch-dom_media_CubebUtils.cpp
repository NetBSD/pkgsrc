$NetBSD: patch-dom_media_CubebUtils.cpp,v 1.1 2025/04/14 15:33:04 nia Exp $

Add Sun Audio support.

--- dom/media/CubebUtils.cpp.orig	2025-03-07 15:26:37.840375420 +0000
+++ dom/media/CubebUtils.cpp
@@ -153,6 +153,7 @@ const char* AUDIOSTREAM_BACKEND_ID_STR[]
   "winmm",
   "directsound",
   "sndio",
+  "sun",
   "opensl",
   "audiotrack",
   "kai"
