$NetBSD: patch-mozilla_gfx_2d_Blur.cpp,v 1.1 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/gfx/2d/Blur.cpp.orig	2013-06-20 04:35:02.000000000 +0000
+++ mozilla/gfx/2d/Blur.cpp
@@ -677,10 +677,10 @@ AlphaBoxBlur::BoxBlur_C(uint8_t* aData,
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
