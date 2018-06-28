$NetBSD: patch-media_libyuv_libyuv_source_mjpeg__decoder.cc,v 1.1 2018/06/28 14:04:10 ryoon Exp $

--- media/libyuv/libyuv/source/mjpeg_decoder.cc.orig	2017-06-05 20:45:14.000000000 +0000
+++ media/libyuv/libyuv/source/mjpeg_decoder.cc
@@ -25,7 +25,7 @@
 #endif
 
 #endif
-struct FILE;  // For jpeglib.h.
+//struct FILE;  // For jpeglib.h.
 
 // C++ build requires extern C for jpeg internals.
 #ifdef __cplusplus
