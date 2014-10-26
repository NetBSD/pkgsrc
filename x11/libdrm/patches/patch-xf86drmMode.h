$NetBSD: patch-xf86drmMode.h,v 1.1 2014/10/26 10:20:10 wiz Exp $

--- xf86drmMode.h.orig	2014-06-14 12:33:26.000000000 +0000
+++ xf86drmMode.h
@@ -449,7 +449,7 @@ extern drmModePlaneResPtr drmModeGetPlan
 extern drmModePlanePtr drmModeGetPlane(int fd, uint32_t plane_id);
 extern int drmModeSetPlane(int fd, uint32_t plane_id, uint32_t crtc_id,
 			   uint32_t fb_id, uint32_t flags,
-			   int32_t crtc_x, int32_t crtc_y,
+			   uint32_t crtc_x, uint32_t crtc_y,
 			   uint32_t crtc_w, uint32_t crtc_h,
 			   uint32_t src_x, uint32_t src_y,
 			   uint32_t src_w, uint32_t src_h);
