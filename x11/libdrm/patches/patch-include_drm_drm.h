$NetBSD: patch-include_drm_drm.h,v 1.2 2014/10/26 10:20:10 wiz Exp $

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
 
@@ -759,6 +763,20 @@ struct drm_prime_handle {
 #define DRM_IOCTL_MODE_OBJ_SETPROPERTY	DRM_IOWR(0xBA, struct drm_mode_obj_set_property)
 #define DRM_IOCTL_MODE_CURSOR2		DRM_IOWR(0xBB, struct drm_mode_cursor2)
 
+#ifdef __NetBSD__
+/*
+ * Instrumenting mmap is trickier than just making an ioctl to do it.
+ */
+struct drm_mmap {
+	void		*dnm_addr;  /* in/out */
+	size_t		dnm_size;   /* in */
+	int		dnm_prot;   /* in */
+	int		dnm_flags;  /* in */
+	off_t		dnm_offset; /* in */
+};
+#define	DRM_IOCTL_MMAP	DRM_IOWR(0xff, struct drm_mmap)
+#endif
+
 /**
  * Device specific ioctls should only be in their respective headers
  * The device specific ioctl range is from 0x40 to 0x99.
