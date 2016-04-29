$NetBSD: patch-include_drm_drm.h,v 1.4 2016/04/29 11:17:34 wiz Exp $

Fix compilation on systems that don't provide O_CLOEXEC.

--- include/drm/drm.h.orig	2016-04-28 00:44:16.000000000 +0000
+++ include/drm/drm.h
@@ -674,7 +674,11 @@ struct drm_set_client_cap {
 };
 
 #define DRM_RDWR O_RDWR
+#ifdef O_CLOEXEC
 #define DRM_CLOEXEC O_CLOEXEC
+#else
+#define DRM_CLOEXEC 0
+#endif
 struct drm_prime_handle {
 	__u32 handle;
 
