$NetBSD: patch-src_r600__textured__videofuncs.c,v 1.1 2014/10/26 10:20:42 wiz Exp $

--- src/r600_textured_videofuncs.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/r600_textured_videofuncs.c
@@ -275,7 +275,8 @@ R600DisplayTexturedVideo(ScrnInfoPtr pSc
 	tex_res.bo                  = accel_state->src_obj[0].bo;
 	tex_res.mip_bo              = accel_state->src_obj[0].bo;
 #ifdef XF86DRM_MODE
-	tex_res.surface             = NULL;
+	if (info->cs)
+		tex_res.surface     = NULL;
 #endif
 
 	tex_res.format              = FMT_8;
@@ -412,7 +413,8 @@ R600DisplayTexturedVideo(ScrnInfoPtr pSc
     cb_conf.base = accel_state->dst_obj.offset;
     cb_conf.bo = accel_state->dst_obj.bo;
 #ifdef XF86DRM_MODE
-    cb_conf.surface = accel_state->dst_obj.surface;
+    if (info->cs)
+        cb_conf.surface = accel_state->dst_obj.surface;
 #endif
 
     switch (accel_state->dst_obj.bpp) {
