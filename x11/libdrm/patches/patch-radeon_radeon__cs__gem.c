$NetBSD: patch-radeon_radeon__cs__gem.c,v 1.1 2014/10/26 10:20:10 wiz Exp $

--- radeon/radeon_cs_gem.c.orig	2014-09-28 16:19:54.000000000 +0000
+++ radeon/radeon_cs_gem.c
@@ -525,9 +525,10 @@ static struct radeon_cs_funcs radeon_cs_
 
 static int radeon_get_device_id(int fd, uint32_t *device_id)
 {
-    struct drm_radeon_info info = {};
+    struct drm_radeon_info info;
     int r;
 
+    memset(&info, 0, sizeof info);
     *device_id = 0;
     info.request = RADEON_INFO_DEVICE_ID;
     info.value = (uintptr_t)device_id;
