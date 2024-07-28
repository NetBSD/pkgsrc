$NetBSD: patch-media_libyuv_source_scale__argb.cc,v 1.1 2024/07/28 18:50:33 nia Exp $

Fix building on NetBSD/evbarm
(Function has wrong prototype for pointer type)

--- media/libyuv/source/scale_argb.cc.orig	2024-07-27 10:57:29.310719802 +0000
+++ media/libyuv/source/scale_argb.cc
@@ -144,12 +144,6 @@ static void ScaleARGBDownEven(int src_wi
     ScaleARGBRowDownEven = filtering ? ScaleARGBRowDownEvenBox_SSE2 :
         ScaleARGBRowDownEven_SSE2;
   }
-#elif defined(HAS_SCALEARGBROWDOWNEVEN_NEON)
-  if (TestCpuFlag(kCpuHasNEON) && IS_ALIGNED(dst_width, 4) &&
-      IS_ALIGNED(src_argb, 4)) {
-    ScaleARGBRowDownEven = filtering ? ScaleARGBRowDownEvenBox_NEON :
-        ScaleARGBRowDownEven_NEON;
-  }
 #endif
 
   if (filtering == kFilterLinear) {
