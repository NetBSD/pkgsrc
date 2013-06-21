$NetBSD: patch-gfx__2d__Blur.cpp,v 1.1 2013/06/21 23:11:42 ryoon Exp $

Bugzilla #883624:
Force pointer/offset arithmetic to be done as ptrdiff_t, to avoid 32bit
underflows on 64bit archs.

--- gfx/2d/Blur.cpp.orig	2013-05-11 21:19:29.000000000 +0200
+++ gfx/2d/Blur.cpp	2013-06-16 11:24:47.000000000 +0200
@@ -670,10 +670,10 @@
   for (int32_t y = 0; y < size.height; y++) {
     bool inSkipRectY = y > skipRect.y && y < skipRect.YMost();
 
-    uint32_t *topLeftBase = innerIntegral + ((y - aTopLobe) * stride32bit - aLeftLobe);
-    uint32_t *topRightBase = innerIntegral + ((y - aTopLobe) * stride32bit + aRightLobe);
-    uint32_t *bottomRightBase = innerIntegral + ((y + aBottomLobe) * stride32bit + aRightLobe);
-    uint32_t *bottomLeftBase = innerIntegral + ((y + aBottomLobe) * stride32bit - aLeftLobe);
+    uint32_t *topLeftBase = innerIntegral + ((ptrdiff_t)(y - aTopLobe) * stride32bit - aLeftLobe);
+    uint32_t *topRightBase = innerIntegral + ((ptrdiff_t)(y - aTopLobe) * stride32bit + aRightLobe);
+    uint32_t *bottomRightBase = innerIntegral + ((ptrdiff_t)(y + aBottomLobe) * stride32bit + aRightLobe);
+    uint32_t *bottomLeftBase = innerIntegral + ((ptrdiff_t)(y + aBottomLobe) * stride32bit - aLeftLobe);
 
     for (int32_t x = 0; x < size.width; x++) {
       if (inSkipRectY && x > skipRect.x && x < skipRect.XMost()) {
