$NetBSD: patch-dom_media_CubebUtils.cpp,v 1.1 2017/04/27 01:49:47 ryoon Exp $

--- dom/media/CubebUtils.cpp.orig	2017-04-11 04:15:21.000000000 +0000
+++ dom/media/CubebUtils.cpp
@@ -71,7 +71,8 @@ const char* AUDIOSTREAM_BACKEND_ID_STR[]
   "sndio",
   "opensl",
   "audiotrack",
-  "kai"
+  "kai",
+  "oss",
 };
 /* Index for failures to create an audio stream the first time. */
 const int CUBEB_BACKEND_INIT_FAILURE_FIRST =
