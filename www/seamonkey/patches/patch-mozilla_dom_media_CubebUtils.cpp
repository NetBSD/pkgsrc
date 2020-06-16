$NetBSD: patch-mozilla_dom_media_CubebUtils.cpp,v 1.2 2020/06/16 09:09:02 nia Exp $

--- mozilla/dom/media/CubebUtils.cpp.orig	2020-04-01 11:01:50.000000000 +0000
+++ mozilla/dom/media/CubebUtils.cpp
@@ -93,6 +93,7 @@ const char* AUDIOSTREAM_BACKEND_ID_STR[]
   "winmm",
   "directsound",
   "sndio",
+  "sun",
   "opensl",
   "audiotrack",
   "kai"
