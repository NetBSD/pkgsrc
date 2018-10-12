$NetBSD: patch-lib_Image.cc,v 1.1 2018/10/12 18:00:55 he Exp $

Sunpro cannot resolve sqrt(int) to either sqrt(double) or
sqrt(long double).

--- lib/Image.cc.orig	2016-07-10 16:31:38.000000000 +0000
+++ lib/Image.cc
@@ -1704,14 +1704,14 @@ void bt::Image::egradient(const Color &f
     for (y = 0; y < height; ++y) {
       for (x = 0; x < width; ++x, ++p) {
         p->red   = static_cast<unsigned char>
-                   (tr - (rsign * static_cast<int>(sqrt(xt[0][x] +
-                                                        yt[0][y]))));
+                   (tr - (rsign * static_cast<int>(sqrt(double(xt[0][x] +
+                                                        yt[0][y])))));
         p->green = static_cast<unsigned char>
-                   (tg - (gsign * static_cast<int>(sqrt(xt[1][x] +
-                                                        yt[1][y]))));
+                   (tg - (gsign * static_cast<int>(sqrt(double(xt[1][x] +
+                                                        yt[1][y])))));
         p->blue  = static_cast<unsigned char>
-                   (tb - (bsign * static_cast<int>(sqrt(xt[2][x] +
-                                                        yt[2][y]))));
+                   (tb - (bsign * static_cast<int>(sqrt(double(xt[2][x] +
+                                                        yt[2][y])))));
       }
     }
   } else {
@@ -1719,14 +1719,14 @@ void bt::Image::egradient(const Color &f
     for (y = 0; y < height; ++y) {
       for (x = 0; x < width; ++x, ++p) {
         p->red   = static_cast<unsigned char>
-                   (tr - (rsign * static_cast<int>(sqrt(xt[0][x]
-                                                        + yt[0][y]))));
+                   (tr - (rsign * static_cast<int>(sqrt(double(xt[0][x]
+                                                        + yt[0][y])))));
         p->green = static_cast<unsigned char>
-                   (tg - (gsign * static_cast<int>(sqrt(xt[1][x]
-                                                        + yt[1][y]))));
+                   (tg - (gsign * static_cast<int>(sqrt(double(xt[1][x]
+                                                        + yt[1][y])))));
         p->blue  = static_cast<unsigned char>
-                   (tb - (bsign * static_cast<int>(sqrt(xt[2][x]
-                                                        + yt[2][y]))));
+                   (tb - (bsign * static_cast<int>(sqrt(double(xt[2][x]
+                                                        + yt[2][y])))));
 
         if (y & 1) {
           p->red   = (p->red   >> 1) + (p->red   >> 2);
