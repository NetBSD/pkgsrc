$NetBSD: patch-src_yimage.cc,v 1.1 2018/11/22 04:56:03 ryo Exp $

--- src/yimage.cc.orig	2013-11-17 16:54:39.000000000 +0000
+++ src/yimage.cc
@@ -246,7 +246,7 @@ YPixmap::~YPixmap() {
 }
 
 void YPixmap::replicate(bool horiz, bool copyMask) {
-    if (this == NULL || pixmap() == None || (fMask == None && copyMask))
+    if (pixmap() == None || (fMask == None && copyMask))
         return;
 
     int dim(horiz ? width() : height());
