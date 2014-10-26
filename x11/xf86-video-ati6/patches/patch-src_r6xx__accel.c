$NetBSD: patch-src_r6xx__accel.c,v 1.1 2014/10/26 10:20:42 wiz Exp $

--- src/r6xx_accel.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/r6xx_accel.c
@@ -228,7 +228,7 @@ r600_set_render_target(ScrnInfoPtr pScrn
 
 
 #if defined(XF86DRM_MODE)
-    if (cb_conf->surface) {
+    if (info->cs && cb_conf->surface) {
 	switch (cb_conf->surface->level[0].mode) {
 	case RADEON_SURF_MODE_1D:
 		array_mode = 2;
@@ -626,7 +626,7 @@ r600_set_tex_resource(ScrnInfoPtr pScrn,
     uint32_t array_mode, pitch;
 
 #if defined(XF86DRM_MODE)
-    if (tex_res->surface) {
+    if (info->cs && tex_res->surface) {
 	switch (tex_res->surface->level[0].mode) {
 	case RADEON_SURF_MODE_1D:
 		array_mode = 2;
