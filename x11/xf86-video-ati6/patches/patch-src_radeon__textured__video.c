$NetBSD: patch-src_radeon__textured__video.c,v 1.1 2014/10/26 10:20:42 wiz Exp $

--- src/radeon_textured_video.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/radeon_textured_video.c
@@ -251,14 +251,17 @@ RADEONPutImageTextured(ScrnInfoPtr pScrn
     BoxRec dstBox;
     int dst_width = width, dst_height = height;
     int aligned_height;
-#ifdef XF86DRM_MODE
-    int h_align = drmmode_get_height_align(pScrn, 0);
-#else
-    int h_align = 1;
-#endif
+    int h_align;
     /* make the compiler happy */
     s2offset = s3offset = srcPitch2 = 0;
 
+#ifdef XF86DRM_MODE
+    if (info->cs)
+        h_align = drmmode_get_height_align(pScrn, 0);
+    else
+#endif
+        h_align = 1;
+
     /* Clip */
     x1 = src_x;
     x2 = src_x + src_w;
@@ -496,7 +499,7 @@ RADEONPutImageTextured(ScrnInfoPtr pScrn
 #ifdef XF86DRI
     if (info->directRenderingEnabled) {
 #ifdef XF86DRM_MODE
-	if (IS_EVERGREEN_3D)
+	if (info->cs && IS_EVERGREEN_3D)
 	    EVERGREENDisplayTexturedVideo(pScrn, pPriv);
 	else
 #endif
