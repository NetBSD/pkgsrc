$NetBSD: patch-src_amdgpu__bo__helper.c,v 1.1 2025/08/08 11:28:14 wiz Exp $

https://gitlab.freedesktop.org/xorg/driver/xf86-video-amdgpu/-/issues/84

--- src/amdgpu_bo_helper.c.orig	2025-08-08 11:23:55.472359613 +0000
+++ src/amdgpu_bo_helper.c
@@ -83,7 +83,7 @@ struct amdgpu_buffer *amdgpu_alloc_pixma
 		if (usage_hint & AMDGPU_CREATE_PIXMAP_SCANOUT)
 			bo_use |= GBM_BO_USE_SCANOUT;
 
-#ifdef HAVE_GBM_BO_USE_FRONT_RENDERING
+#if HAVE_GBM_BO_USE_FRONT_RENDERING
 		if (usage_hint & AMDGPU_CREATE_PIXMAP_FRONT)
 			bo_use |= GBM_BO_USE_FRONT_RENDERING;
 #endif
