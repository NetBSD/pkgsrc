$NetBSD: patch-radeon_radeon__bo__gem.c,v 1.2 2019/01/18 23:09:55 tnn Exp $

--- radeon/radeon_bo_gem.c.orig	2014-09-28 16:19:54.000000000 +0000
+++ radeon/radeon_bo_gem.c
@@ -252,9 +252,10 @@ static int bo_set_tiling(struct radeon_b
 static int bo_get_tiling(struct radeon_bo_int *boi, uint32_t *tiling_flags,
                          uint32_t *pitch)
 {
-    struct drm_radeon_gem_set_tiling args = {};
+    struct drm_radeon_gem_set_tiling args;
     int r;
 
+    memset(&args, 0, sizeof args);
     args.handle = boi->handle;
 
     r = drmCommandWriteRead(boi->bom->fd,
