$NetBSD: patch-src_yimage.cc,v 1.1 2018/11/22 04:56:03 ryo Exp $

* "this" must not be null. comparison with null will be removed by compiler optimization.

--- src/yimage.cc.orig	2009-11-08 18:59:46.000000000 +0000
+++ src/yimage.cc
@@ -244,7 +244,7 @@ YPixmap::~YPixmap() {
 }
 
 void YPixmap::replicate(bool horiz, bool copyMask) {
-    if (this == NULL || pixmap() == None || (fMask == None && copyMask))
+    if (pixmap() == None || (fMask == None && copyMask))
         return;
 
     int dim(horiz ? width() : height());
