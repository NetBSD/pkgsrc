$NetBSD: patch-dom_media_CubebUtils.cpp,v 1.2 2018/11/04 00:38:44 ryoon Exp $

--- dom/media/CubebUtils.cpp.orig	2018-10-18 20:06:04.000000000 +0000
+++ dom/media/CubebUtils.cpp
@@ -159,7 +159,8 @@ const char* AUDIOSTREAM_BACKEND_ID_STR[]
   "sndio",
   "opensl",
   "audiotrack",
-  "kai"
+  "kai",
+  "oss",
 };
 /* Index for failures to create an audio stream the first time. */
 const int CUBEB_BACKEND_INIT_FAILURE_FIRST =
