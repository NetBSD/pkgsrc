$NetBSD: patch-wxc_src_image.cpp,v 1.1 2015/02/20 23:39:31 joerg Exp $

--- wxc/src/image.cpp.orig	2015-02-20 22:58:51.000000000 +0000
+++ wxc/src/image.cpp
@@ -60,9 +60,9 @@ EWXWEXPORT(int, wxcGetPixelRGB)( unsigne
 
 EWXWEXPORT(void, wxcSetPixelRowRGB)( unsigned char* buffer, int width, int x, int y, int rgb0, int rgb1, int count )
 {
-  int r0  = ((rgb0 >> 16) && 0xFF);
-  int g0  = ((rgb0 >>  8) && 0xFF);
-  int b0  = (rgb0 && 0xFF);
+  int r0  = ((rgb0 >> 16) & 0xFF);
+  int g0  = ((rgb0 >>  8) & 0xFF);
+  int b0  = (rgb0 & 0xFF);
   int start = 3*(width*y+x);
   int i;
   
@@ -76,9 +76,9 @@ EWXWEXPORT(void, wxcSetPixelRowRGB)( uns
   }
   else {  
     /* do linear interpolation of the color */
-    int r1  = ((rgb1 >> 16) && 0xFF);
-    int g1  = ((rgb1 >>  8) && 0xFF);
-    int b1  = (rgb1 && 0xFF);
+    int r1  = ((rgb1 >> 16) & 0xFF);
+    int g1  = ((rgb1 >>  8) & 0xFF);
+    int b1  = (rgb1 & 0xFF);
 
     int rd  = ((r1 - r0) << 16) / (count-1);
     int gd  = ((g1 - g0) << 16) / (count-1);
@@ -102,9 +102,9 @@ EWXWEXPORT(void, wxcSetPixelRowRGB)( uns
 EWXWEXPORT(void, wxcInitPixelsRGB)( unsigned char* buffer, int width, int height, int rgb )
 {
   int count        = width*height*3;
-  unsigned char r  = ((rgb >> 16) && 0xFF);
-  unsigned char g  = ((rgb >>  8) && 0xFF);
-  unsigned char b  = rgb && 0xFF;
+  unsigned char r  = ((rgb >> 16) & 0xFF);
+  unsigned char g  = ((rgb >>  8) & 0xFF);
+  unsigned char b  = rgb & 0xFF;
   int i;
 
   if (r==g && g==b) {
