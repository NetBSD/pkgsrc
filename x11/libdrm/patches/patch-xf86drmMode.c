$NetBSD: patch-xf86drmMode.c,v 1.2 2015/04/11 10:02:11 sevan Exp $

Disable checking for hw.dri.%d.modesetting.
This sysctl is only available if a KMS module is loaded. But the libdrm
check happens before X got a chance of loading the KMS module.

--- xf86drmMode.c.orig	2015-03-18 17:33:36.000000000 +0000
+++ xf86drmMode.c
@@ -771,38 +771,20 @@ int drmCheckModesettingSupported(const c
 	if (found)
 		return 0;
 #elif defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
-	char kbusid[1024], sbusid[1024];
-	char oid[128];
-	int domain, bus, dev, func;
-	int i, modesetting, ret;
-	size_t len;
-
-	ret = sscanf(busid, "pci:%04x:%02x:%02x.%d", &domain, &bus, &dev,
-	    &func);
-	if (ret != 4)
+	return 0;
+#elif defined(__NetBSD__)
+	int fd;
+	static const struct drm_mode_card_res zero_res;
+	struct drm_mode_card_res res = zero_res;
+	int ret;
+ 
+	fd = drmOpen(NULL, busid);
+	if (fd == -1)
 		return -EINVAL;
-	snprintf(kbusid, sizeof(kbusid), "pci:%04x:%02x:%02x.%d", domain, bus,
-	    dev, func);
-
-	/* How many GPUs do we expect in the machine ? */
-	for (i = 0; i < 16; i++) {
-		snprintf(oid, sizeof(oid), "hw.dri.%d.busid", i);
-		len = sizeof(sbusid);
-		ret = sysctlbyname(oid, sbusid, &len, NULL, 0);
-		if (ret == -1) {
-			if (errno == ENOENT)
-				continue;
-			return -EINVAL;
-		}
-		if (strcmp(sbusid, kbusid) != 0)
-			continue;
-		snprintf(oid, sizeof(oid), "hw.dri.%d.modesetting", i);
-		len = sizeof(modesetting);
-		ret = sysctlbyname(oid, &modesetting, &len, NULL, 0);
-		if (ret == -1 || len != sizeof(modesetting))
-			return -EINVAL;
-		return (modesetting ? 0 : -ENOSYS);
-	}
+	ret = drmIoctl(fd, DRM_IOCTL_MODE_GETRESOURCES, &res);
+	drmClose(fd);
+	if (ret == 0)
+		return 0;
 #elif defined(__DragonFly__)
 	return 0;
 #endif
@@ -907,7 +889,7 @@ int drmModePageFlip(int fd, uint32_t crt
 
 int drmModeSetPlane(int fd, uint32_t plane_id, uint32_t crtc_id,
 		    uint32_t fb_id, uint32_t flags,
-		    int32_t crtc_x, int32_t crtc_y,
+		    uint32_t crtc_x, uint32_t crtc_y,
 		    uint32_t crtc_w, uint32_t crtc_h,
 		    uint32_t src_x, uint32_t src_y,
 		    uint32_t src_w, uint32_t src_h)
