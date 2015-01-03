$NetBSD: patch-include_drm_drm.h,v 1.3 2015/01/03 10:01:40 wiz Exp $

Fix compilation on systems that don't provide O_CLOEXEC.

--- include/drm/drm.h.orig	2014-06-14 12:33:26.000000000 +0000
+++ include/drm/drm.h
@@ -641,7 +641,11 @@ struct drm_set_client_cap {
 	__u64 value;
 };
 
+#ifdef O_CLOEXEC
 #define DRM_CLOEXEC O_CLOEXEC
+#else
+#define DRM_CLOEXEC 0
+#endif
 struct drm_prime_handle {
 	__u32 handle;
 
