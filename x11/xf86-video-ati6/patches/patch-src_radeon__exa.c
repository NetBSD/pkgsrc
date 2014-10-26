$NetBSD: patch-src_radeon__exa.c,v 1.1 2014/10/26 10:20:42 wiz Exp $

--- src/radeon_exa.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/radeon_exa.c
@@ -498,7 +498,7 @@ void *RADEONEXACreatePixmap2(ScreenPtr p
     memset(&surface, 0, sizeof(struct radeon_surface));
 
 #ifdef XF86DRM_MODE
-    if (info->ChipFamily >= CHIP_FAMILY_R600 && info->surf_man) {
+    if (info->cs && info->ChipFamily >= CHIP_FAMILY_R600 && info->surf_man) {
 		if (width) {
 			surface.npix_x = width;
 			/* need to align height to 8 for old kernel */
