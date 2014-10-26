$NetBSD: patch-src_r600__exa.c,v 1.1 2014/10/26 10:20:42 wiz Exp $

--- src/r600_exa.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/r600_exa.c
@@ -246,7 +246,8 @@ R600PrepareSolid(PixmapPtr pPix, int alu
     cb_conf.base = accel_state->dst_obj.offset;
     cb_conf.bo = accel_state->dst_obj.bo;
 #ifdef XF86DRM_MODE
-    cb_conf.surface = accel_state->dst_obj.surface;
+    if (info->cs) 
+        cb_conf.surface = accel_state->dst_obj.surface;
 #endif
 
     if (accel_state->dst_obj.bpp == 8) {
@@ -428,7 +429,8 @@ R600DoPrepareCopy(ScrnInfoPtr pScrn)
     tex_res.bo                  = accel_state->src_obj[0].bo;
     tex_res.mip_bo              = accel_state->src_obj[0].bo;
 #ifdef XF86DRM_MODE
-    tex_res.surface             = accel_state->src_obj[0].surface;
+    if (info->cs) 
+        tex_res.surface             = accel_state->src_obj[0].surface;
 #endif
     if (accel_state->src_obj[0].bpp == 8) {
 	tex_res.format              = FMT_8;
@@ -475,7 +477,8 @@ R600DoPrepareCopy(ScrnInfoPtr pScrn)
     cb_conf.base = accel_state->dst_obj.offset;
     cb_conf.bo = accel_state->dst_obj.bo;
 #ifdef XF86DRM_MODE
-    cb_conf.surface = accel_state->dst_obj.surface;
+    if (info->cs) 
+        cb_conf.surface = accel_state->dst_obj.surface;
 #endif
     if (accel_state->dst_obj.bpp == 8) {
 	cb_conf.format = COLOR_8;
@@ -626,15 +629,10 @@ R600PrepareCopy(PixmapPtr pSrc,   Pixmap
 
     if (accel_state->same_surface == TRUE) {
 #if defined(XF86DRM_MODE)
-	unsigned long size = accel_state->dst_obj.surface->bo_size;
-	unsigned long align = accel_state->dst_obj.surface->bo_alignment;
-#else
-	unsigned height = pDst->drawable.height;
-	unsigned long size = height * accel_state->dst_obj.pitch * pDst->drawable.bitsPerPixel/8;
-#endif
-
-#if defined(XF86DRM_MODE)
 	if (info->cs) {
+	    unsigned long size = accel_state->dst_obj.surface->bo_size;
+	    unsigned long align = accel_state->dst_obj.surface->bo_alignment;
+
 	    if (accel_state->copy_area_bo) {
 		radeon_bo_unref(accel_state->copy_area_bo);
 		accel_state->copy_area_bo = NULL;
@@ -656,6 +654,9 @@ R600PrepareCopy(PixmapPtr pSrc,   Pixmap
 	} else
 #endif
 	{
+	    unsigned height = pDst->drawable.height;
+	    unsigned long size = height * accel_state->dst_obj.pitch * pDst->drawable.bitsPerPixel/8;
+
 	    if (accel_state->copy_area) {
 		exaOffscreenFree(pDst->drawable.pScreen, accel_state->copy_area);
 		accel_state->copy_area = NULL;
@@ -978,7 +979,8 @@ static Bool R600TextureSetup(PicturePtr 
     tex_res.bo                  = accel_state->src_obj[unit].bo;
     tex_res.mip_bo              = accel_state->src_obj[unit].bo;
 #ifdef XF86DRM_MODE
-    tex_res.surface             = accel_state->src_obj[unit].surface;
+    if (info->cs) 
+        tex_res.surface             = accel_state->src_obj[unit].surface;
 #endif
     tex_res.request_size        = 1;
 
@@ -1447,7 +1449,8 @@ static Bool R600PrepareComposite(int op,
     cb_conf.format = dst_format;
     cb_conf.bo = accel_state->dst_obj.bo;
 #ifdef XF86DRM_MODE
-    cb_conf.surface = accel_state->dst_obj.surface;
+    if (info->cs) 
+        cb_conf.surface = accel_state->dst_obj.surface;
 #endif
 
     switch (pDstPicture->format) {
@@ -1899,9 +1902,7 @@ R600UploadToScreenCS(PixmapPtr pDst, int
     src_obj.domain = RADEON_GEM_DOMAIN_GTT;
     src_obj.bo = scratch;
     src_obj.tiling_flags = 0;
-#ifdef XF86DRM_MODE
     src_obj.surface = NULL;
-#endif
 
     dst_obj.pitch = dst_pitch_hw;
     dst_obj.width = pDst->drawable.width;
@@ -1911,9 +1912,7 @@ R600UploadToScreenCS(PixmapPtr pDst, int
     dst_obj.domain = RADEON_GEM_DOMAIN_VRAM;
     dst_obj.bo = radeon_get_pixmap_bo(pDst);
     dst_obj.tiling_flags = radeon_get_pixmap_tiling(pDst);
-#ifdef XF86DRM_MODE
     dst_obj.surface = radeon_get_pixmap_surface(pDst);
-#endif
 
     if (!R600SetAccelState(pScrn,
 			   &src_obj,
@@ -2040,9 +2039,7 @@ R600DownloadFromScreenCS(PixmapPtr pSrc,
     src_obj.domain = RADEON_GEM_DOMAIN_VRAM | RADEON_GEM_DOMAIN_GTT;
     src_obj.bo = radeon_get_pixmap_bo(pSrc);
     src_obj.tiling_flags = radeon_get_pixmap_tiling(pSrc);
-#ifdef XF86DRM_MODE
     src_obj.surface = radeon_get_pixmap_surface(pSrc);
-#endif
 
     dst_obj.pitch = scratch_pitch;
     dst_obj.width = w;
@@ -2052,9 +2049,7 @@ R600DownloadFromScreenCS(PixmapPtr pSrc,
     dst_obj.bpp = bpp;
     dst_obj.domain = RADEON_GEM_DOMAIN_GTT;
     dst_obj.tiling_flags = 0;
-#ifdef XF86DRM_MODE
     dst_obj.surface = NULL;
-#endif
 
     if (!R600SetAccelState(pScrn,
 			   &src_obj,
