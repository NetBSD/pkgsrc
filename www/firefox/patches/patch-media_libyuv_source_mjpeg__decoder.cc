$NetBSD: patch-media_libyuv_source_mjpeg__decoder.cc,v 1.1 2016/12/03 09:58:26 ryoon Exp $

--- media/libyuv/source/mjpeg_decoder.cc.orig	2016-10-31 20:15:24.000000000 +0000
+++ media/libyuv/source/mjpeg_decoder.cc
@@ -25,7 +25,6 @@
 #endif
 
 #endif
-struct FILE;  // For jpeglib.h.
 
 // C++ build requires extern C for jpeg internals.
 #ifdef __cplusplus
