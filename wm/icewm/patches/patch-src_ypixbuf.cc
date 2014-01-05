$NetBSD: patch-src_ypixbuf.cc,v 1.1 2014/01/05 12:29:33 ryoon Exp $

From http://www.yagoto-urayama.jp/~oshimaya/netbsd/files/icewm-1.2.35.diff
Fix color

--- src/ypixbuf.cc.orig	2009-11-08 18:59:46.000000000 +0000
+++ src/ypixbuf.cc
@@ -570,6 +570,23 @@ static void copyPixbufToRGB32(unsigned c
 }
 
 template <int Channels>
+static void copyPixbufToBGR32(unsigned char const * src, unsigned const sStep,
+                              char * dst, unsigned const dStep,
+                              unsigned const width, unsigned const height) {
+    MSG(("copyPixbufToRGB32"));
+
+    for (unsigned y(height); y > 0; --y, src+= sStep, dst+= dStep) {
+        unsigned char const * s(src); char * d(dst);
+        for (unsigned x(width); x-- > 0; s+= Channels, d+= 4)
+        {
+                d[0] = s[0];
+                d[1] = s[1];
+                d[2] = s[2];
+        }
+    }
+}
+
+template <int Channels>
 static void copyPixbufToRGB565(unsigned char const * src, unsigned const sStep,
                                char * dst, unsigned const dStep,
                                unsigned const width, unsigned const height) {
@@ -651,10 +668,12 @@ static void copyPixbufToImage(YPixbuf::P
     unsigned const width(image.width), height(image.height);
 
     if (image.depth > 16) {
-        if (CHANNEL_MASK(image, 0xff0000, 0x00ff00, 0x0000ff) ||
-            CHANNEL_MASK(image, 0x0000ff, 0x00ff00, 0xff0000))
+        if (CHANNEL_MASK(image, 0xff0000, 0x00ff00, 0x0000ff))
             copyPixbufToRGB32<Channels> (pixels, rowstride,
                      image.data, image.bytes_per_line, width, height);
+        else if (CHANNEL_MASK(image, 0x0000ff, 0x00ff00, 0xff0000))
+            copyPixbufToBGR32<Channels> (pixels, rowstride,
+                     image.data, image.bytes_per_line, width, height);
         else
             copyPixbufToRGBAny<yuint32, Channels> (pixels, rowstride,
                 image.data, image.bytes_per_line, width, height,
