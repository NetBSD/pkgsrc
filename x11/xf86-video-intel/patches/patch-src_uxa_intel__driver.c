$NetBSD: patch-src_uxa_intel__driver.c,v 1.1 2016/01/05 13:05:37 tnn Exp $

fix build with xorg-server-1.18

--- src/uxa/intel_driver.c.orig	2014-12-09 20:43:22.000000000 +0000
+++ src/uxa/intel_driver.c
@@ -642,7 +642,11 @@ redisplay_dirty(ScreenPtr screen, Pixmap
 		return;
 
 	PixmapRegionInit(&pixregion, dirty->slave_dst->master_pixmap);
+#ifdef HAS_DIRTYTRACKING_ROTATION
+	PixmapSyncDirtyHelper(dirty);
+#else
 	PixmapSyncDirtyHelper(dirty, &pixregion);
+#endif
 	RegionUninit(&pixregion);
 
         intel_flush(intel);
