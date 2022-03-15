$NetBSD: patch-src_sna_kgem.c,v 1.1 2022/03/15 18:53:42 tnn Exp $

https://gitlab.freedesktop.org/xorg/driver/xf86-video-intel/-/issues/171
https://gitlab.freedesktop.org/E5ten/xf86-video-intel/-/commit/a92ccaf05efe8f11b3c5cd217d48ad3cf4caa090

--- src/sna/kgem.c.orig	2021-01-15 20:59:05.000000000 +0000
+++ src/sna/kgem.c
@@ -2861,7 +2861,7 @@ static bool kgem_bo_move_to_cache(struct
 static struct kgem_bo *
 search_snoop_cache(struct kgem *kgem, unsigned int num_pages, unsigned flags)
 {
-	struct kgem_bo *bo, *first = NULL;
+	struct kgem_bo *bo = NULL, *first = NULL;
 
 	DBG(("%s: num_pages=%d, flags=%x\n", __FUNCTION__, num_pages, flags));
 
@@ -3127,7 +3127,7 @@ void kgem_retire__buffers(struct kgem *k
 
 static bool kgem_retire__flushing(struct kgem *kgem)
 {
-	struct kgem_bo *bo, *next;
+	struct kgem_bo *bo = NULL, *next;
 	bool retired = false;
 
 	list_for_each_entry_safe(bo, next, &kgem->flushing, request) {
@@ -3425,7 +3425,7 @@ static void kgem_commit__check_reloc(str
 #ifndef NDEBUG
 static void kgem_commit__check_buffers(struct kgem *kgem)
 {
-	struct kgem_buffer *bo;
+	struct kgem_buffer *bo = NULL;
 
 	list_for_each_entry(bo, &kgem->active_buffers, base.list)
 		assert(bo->base.exec == NULL);
@@ -3437,7 +3437,7 @@ static void kgem_commit__check_buffers(s
 static void kgem_commit(struct kgem *kgem)
 {
 	struct kgem_request *rq = kgem->next_request;
-	struct kgem_bo *bo, *next;
+	struct kgem_bo *bo = NULL, *next;
 
 	kgem_commit__check_reloc(kgem);
 
@@ -3551,7 +3551,7 @@ static void kgem_close_inactive(struct k
 
 static void kgem_finish_buffers(struct kgem *kgem)
 {
-	struct kgem_buffer *bo, *next;
+	struct kgem_buffer *bo = NULL, *next;
 
 	list_for_each_entry_safe(bo, next, &kgem->batch_buffers, base.list) {
 		DBG(("%s: buffer handle=%d, used=%d, exec?=%d, write=%d, mmapped=%s, refcnt=%d\n",
@@ -3940,7 +3940,7 @@ static int compact_batch_surface(struct 
 
 static struct kgem_bo *first_available(struct kgem *kgem, struct list *list)
 {
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 
 	list_for_each_entry(bo, list, list) {
 		assert(bo->refcnt > 0);
@@ -4224,7 +4224,7 @@ void _kgem_submit(struct kgem *kgem)
 		       kgem->nreloc, kgem->nexec, kgem->nfence, kgem->aperture, kgem->aperture_fenced, kgem->aperture_high, kgem->aperture_total, -ret);
 
 		for (i = 0; i < kgem->nexec; i++) {
-			struct kgem_bo *bo, *found = NULL;
+			struct kgem_bo *bo = NULL, *found = NULL;
 
 			list_for_each_entry(bo, &kgem->next_request->buffers, request) {
 				if (bo->handle == kgem->exec[i].handle) {
@@ -4588,7 +4588,7 @@ bool kgem_cleanup_cache(struct kgem *kge
 static struct kgem_bo *
 search_linear_cache(struct kgem *kgem, unsigned int num_pages, unsigned flags)
 {
-	struct kgem_bo *bo, *first = NULL;
+	struct kgem_bo *bo = NULL, *first = NULL;
 	bool use_active = (flags & CREATE_INACTIVE) == 0;
 	struct list *cache;
 
@@ -5392,7 +5392,7 @@ struct kgem_bo *kgem_create_2d(struct kg
 			       uint32_t flags)
 {
 	struct list *cache;
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 	uint32_t pitch, tiled_height, size;
 	uint32_t handle;
 	int i, bucket, retry;
@@ -7245,7 +7245,7 @@ void kgem_bo_sync__gtt(struct kgem *kgem
 void kgem_clear_dirty(struct kgem *kgem)
 {
 	struct list * const buffers = &kgem->next_request->buffers;
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 
 	list_for_each_entry(bo, buffers, request) {
 		if (!bo->gpu_dirty)
@@ -7525,7 +7525,7 @@ struct kgem_bo *kgem_create_buffer(struc
 				   uint32_t size, uint32_t flags,
 				   void **ret)
 {
-	struct kgem_buffer *bo;
+	struct kgem_buffer *bo = NULL;
 	unsigned offset, alloc;
 	struct kgem_bo *old;
 
