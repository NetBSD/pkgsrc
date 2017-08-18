$NetBSD: patch-mozilla_media_libyuv_source_mjpeg__decoder.cc,v 1.1 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/media/libyuv/source/mjpeg_decoder.cc.orig	2017-07-07 05:37:17.000000000 +0000
+++ mozilla/media/libyuv/source/mjpeg_decoder.cc
@@ -25,7 +25,6 @@
 #endif
 
 #endif
-struct FILE;  // For jpeglib.h.
 
 // C++ build requires extern C for jpeg internals.
 #ifdef __cplusplus
