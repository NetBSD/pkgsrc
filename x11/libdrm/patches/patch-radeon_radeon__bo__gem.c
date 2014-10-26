$NetBSD: patch-radeon_radeon__bo__gem.c,v 1.1 2014/10/26 10:20:10 wiz Exp $

--- radeon/radeon_bo_gem.c.orig	2014-09-28 16:19:54.000000000 +0000
+++ radeon/radeon_bo_gem.c
@@ -178,8 +178,8 @@ static int bo_map(struct radeon_bo_int *
                 boi, boi->handle, r);
         return r;
     }
-    ptr = drm_mmap(0, args.size, PROT_READ|PROT_WRITE, MAP_SHARED, boi->bom->fd, args.addr_ptr);
-    if (ptr == MAP_FAILED)
+    r = drmMap(boi->bom->fd, args.addr_ptr, args.size, &ptr);
+    if (r)
         return -errno;
     bo_gem->priv_ptr = ptr;
 wait:
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
