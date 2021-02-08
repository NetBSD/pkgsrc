$NetBSD: patch-mozilla_dom_media_CubebUtils.cpp,v 1.3 2021/02/08 12:26:20 ryoon Exp $

--- dom/media/CubebUtils.cpp.orig	2020-04-01 11:01:50.000000000 +0000
+++ dom/media/CubebUtils.cpp
@@ -93,6 +93,7 @@ const char* AUDIOSTREAM_BACKEND_ID_STR[]
   "winmm",
   "directsound",
   "sndio",
+  "sun",
   "opensl",
   "audiotrack",
   "kai"
