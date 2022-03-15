$NetBSD: patch-src_sna_kgem__debug.c,v 1.1 2022/03/15 18:53:42 tnn Exp $

https://gitlab.freedesktop.org/xorg/driver/xf86-video-intel/-/issues/171
https://gitlab.freedesktop.org/E5ten/xf86-video-intel/-/commit/a92ccaf05efe8f11b3c5cd217d48ad3cf4caa090

--- src/sna/kgem_debug.c.orig	2021-01-15 20:59:05.000000000 +0000
+++ src/sna/kgem_debug.c
@@ -56,7 +56,7 @@ struct kgem_bo *
 kgem_debug_get_bo_for_reloc_entry(struct kgem *kgem,
 				  struct drm_i915_gem_relocation_entry *reloc)
 {
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 
 	if (reloc == NULL)
 		return NULL;
@@ -86,7 +86,7 @@ static int kgem_debug_handle_is_fenced(s
 
 static int kgem_debug_handle_tiling(struct kgem *kgem, uint32_t handle)
 {
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 
 	list_for_each_entry(bo, &kgem->next_request->buffers, request)
 		if (bo->target_handle == handle)
