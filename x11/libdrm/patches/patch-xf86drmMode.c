$NetBSD: patch-xf86drmMode.c,v 1.1 2014/10/26 10:20:10 wiz Exp $

--- xf86drmMode.c.orig	2014-08-27 18:04:46.000000000 +0000
+++ xf86drmMode.c
@@ -806,6 +806,19 @@ int drmCheckModesettingSupported(const c
 			return -EINVAL;
 		return (modesetting ? 0 : -ENOSYS);
 	}
+#elif defined(__NetBSD__)
+	int fd;
+	static const struct drm_mode_card_res zero_res;
+	struct drm_mode_card_res res = zero_res;
+	int ret;
+ 
+	fd = drmOpen(NULL, busid);
+	if (fd == -1)
+		return -EINVAL;
+	ret = drmIoctl(fd, DRM_IOCTL_MODE_GETRESOURCES, &res);
+	drmClose(fd);
+	if (ret == 0)
+		return 0;
 #elif defined(__DragonFly__)
 	return 0;
 #endif
@@ -908,7 +921,7 @@ int drmModePageFlip(int fd, uint32_t crt
 
 int drmModeSetPlane(int fd, uint32_t plane_id, uint32_t crtc_id,
 		    uint32_t fb_id, uint32_t flags,
-		    int32_t crtc_x, int32_t crtc_y,
+		    uint32_t crtc_x, uint32_t crtc_y,
 		    uint32_t crtc_w, uint32_t crtc_h,
 		    uint32_t src_x, uint32_t src_y,
 		    uint32_t src_w, uint32_t src_h)
