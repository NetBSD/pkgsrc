$NetBSD: patch-src_radeon__kms.c,v 1.4 2017/02/02 18:54:44 wiz Exp $

From FreeBSD ports / DragonFly dports
PR 50067

--- src/radeon_kms.c.orig	2016-11-17 02:23:37.000000000 +0000
+++ src/radeon_kms.c
@@ -30,6 +30,12 @@
 
 #include <errno.h>
 #include <sys/ioctl.h>
+
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#include <sys/param.h>
+#include <sys/linker.h>
+#endif
+
 /* Driver data structures */
 #include "radeon.h"
 #include "radeon_drm_queue.h"
@@ -811,7 +817,7 @@ radeon_dirty_update(ScrnInfoPtr scrn)
 {
 	RADEONInfoPtr info = RADEONPTR(scrn);
 	ScreenPtr screen = scrn->pScreen;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 	RegionPtr region;
 
 	xorg_list_for_each_entry(ent, &screen->pixmap_dirty_list, ent) {
@@ -1391,7 +1397,11 @@ static int radeon_get_drm_master_fd(Scrn
 #endif
     struct pci_device *dev = info->PciInfo;
     char *busid;
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    int fd, err;
+#else
     int fd;
+#endif
 
 #ifdef XF86_PDEV_SERVER_FD
     if (pRADEONEnt->platform_dev) {
@@ -1405,6 +1415,17 @@ static int radeon_get_drm_master_fd(Scrn
     XNFasprintf(&busid, "pci:%04x:%02x:%02x.%d",
                 dev->domain, dev->bus, dev->dev, dev->func);
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    err = kldload("radeonkms");
+    if (err == -1 && errno != EEXIST) {
+        xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+               "[drm] Failed to load kernel module for %s: %s\n",
+               busid, strerror(errno));
+        free(busid);
+        return -1;
+    }
+#endif
+
     fd = drmOpen(NULL, busid);
     if (fd == -1)
 	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
