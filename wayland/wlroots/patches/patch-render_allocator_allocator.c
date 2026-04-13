$NetBSD: patch-render_allocator_allocator.c,v 1.1 2026/04/13 17:20:09 kikadf Exp $

* On NetBSD the stub drm_mode_create_lease_ioctl() always returns with -ENODEV,
  but after drmModeCreateLease() only allowed -EINVAL and -EOPNOTSUPP
* Call reopen_drm_node() with the correct fd
  backend(card[0-3]) vs. renderer(renderD[128-131])

--- render/allocator/allocator.c.orig	2025-10-21 22:21:53.000000000 +0000
+++ render/allocator/allocator.c
@@ -37,6 +37,7 @@ void wlr_allocator_init(struct wlr_alloc
  */
 static int reopen_drm_node(int drm_fd, bool allow_render_node) {
 	if (drmIsMaster(drm_fd)) {
+#if !defined(__NetBSD__)
 		// Only recent kernels support empty leases
 		uint32_t lessee_id;
 		int lease_fd = drmModeCreateLease(drm_fd, NULL, 0, O_CLOEXEC, &lessee_id);
@@ -46,6 +47,7 @@ static int reopen_drm_node(int drm_fd, b
 			wlr_log_errno(WLR_ERROR, "drmModeCreateLease failed");
 			return -1;
 		}
+#endif
 		wlr_log(WLR_DEBUG, "drmModeCreateLease failed, "
 			"falling back to plain open");
 	}
@@ -99,18 +101,12 @@ struct wlr_allocator *wlr_allocator_auto
 		struct wlr_renderer *renderer) {
 	uint32_t backend_caps = backend->buffer_caps;
 	uint32_t renderer_caps = renderer->render_buffer_caps;
-
-	// Note, drm_fd may be negative if unavailable
-	int drm_fd = wlr_backend_get_drm_fd(backend);
-	if (drm_fd < 0) {
-		drm_fd = wlr_renderer_get_drm_fd(renderer);
-	}
-
+	int drm_fd = -1;
 	struct wlr_allocator *alloc = NULL;
 
 	uint32_t gbm_caps = WLR_BUFFER_CAP_DMABUF;
-	if ((backend_caps & gbm_caps) && (renderer_caps & gbm_caps)
-			&& drm_fd >= 0) {
+	if ((backend_caps & gbm_caps) && (renderer_caps & gbm_caps) &&
+	    ((drm_fd = wlr_renderer_get_drm_fd(renderer)) >= 0)) {
 #if WLR_HAS_GBM_ALLOCATOR
 		wlr_log(WLR_DEBUG, "Trying to create gbm allocator");
 		int gbm_fd = reopen_drm_node(drm_fd, true);
@@ -137,8 +133,9 @@ struct wlr_allocator *wlr_allocator_auto
 	}
 
 	uint32_t drm_caps = WLR_BUFFER_CAP_DMABUF | WLR_BUFFER_CAP_DATA_PTR;
-	if ((backend_caps & drm_caps) && (renderer_caps & drm_caps)
-			&& drm_fd >= 0 && drmIsMaster(drm_fd)) {
+	if ((backend_caps & drm_caps) && (renderer_caps & drm_caps) &&
+	    ((drm_fd = wlr_backend_get_drm_fd(backend)) >= 0) &&
+	    drmIsMaster(drm_fd)) {
 		wlr_log(WLR_DEBUG, "Trying to create drm dumb allocator");
 		int dumb_fd = reopen_drm_node(drm_fd, false);
 		if (dumb_fd < 0) {
