$NetBSD: patch-render_drm__syncobj.c,v 1.1 2026/04/13 17:20:09 kikadf Exp $

* Use ETIMEDOUT instead of ETIME

--- render/drm_syncobj.c.orig	2025-09-13 13:32:29.063861299 +0000
+++ render/drm_syncobj.c
@@ -161,7 +161,7 @@ out:
 bool wlr_drm_syncobj_timeline_check(struct wlr_drm_syncobj_timeline *timeline,
 		uint64_t point, uint32_t flags, bool *result) {
 	int etime;
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__)|| defined(__NetBSD__)
 	etime = ETIMEDOUT;
 #else
 	etime = ETIME;
