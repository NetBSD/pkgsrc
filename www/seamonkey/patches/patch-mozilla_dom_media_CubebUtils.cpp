$NetBSD: patch-mozilla_dom_media_CubebUtils.cpp,v 1.1 2020/05/06 14:34:53 ryoon Exp $

--- mozilla/dom/media/CubebUtils.cpp.orig	2020-04-01 11:01:50.000000000 +0000
+++ mozilla/dom/media/CubebUtils.cpp
@@ -95,7 +95,8 @@ const char* AUDIOSTREAM_BACKEND_ID_STR[]
   "sndio",
   "opensl",
   "audiotrack",
-  "kai"
+  "kai",
+  "oss",
 };
 /* Index for failures to create an audio stream the first time. */
 const int CUBEB_BACKEND_INIT_FAILURE_FIRST =
