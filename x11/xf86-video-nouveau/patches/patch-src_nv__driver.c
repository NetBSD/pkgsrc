$NetBSD: patch-src_nv__driver.c,v 1.1 2022/08/14 23:35:48 tnn Exp $

Can't have forbidden word in the source.
Thus we have the forbidden word in the patch instead.

--- src/nv_driver.c.orig	2019-01-29 04:41:58.000000000 +0000
+++ src/nv_driver.c
@@ -559,16 +559,16 @@ redisplay_dirty(ScreenPtr screen, Pixmap
 {
 	RegionRec pixregion;
 
-	PixmapRegionInit(&pixregion, dirty->slave_dst);
+	PixmapRegionInit(&pixregion, dirty->secondary_dst);
 
-	DamageRegionAppend(&dirty->slave_dst->drawable, &pixregion);
+	DamageRegionAppend(&dirty->secondary_dst->drawable, &pixregion);
 #ifdef HAS_DIRTYTRACKING_ROTATION
 	PixmapSyncDirtyHelper(dirty);
 #else
 	PixmapSyncDirtyHelper(dirty, &pixregion);
 #endif
 
-	DamageRegionProcessPending(&dirty->slave_dst->drawable);
+	DamageRegionProcessPending(&dirty->secondary_dst->drawable);
 	RegionUninit(&pixregion);
 }
 
