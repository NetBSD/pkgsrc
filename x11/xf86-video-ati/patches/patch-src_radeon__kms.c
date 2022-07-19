$NetBSD: patch-src_radeon__kms.c,v 1.6 2022/07/19 11:59:05 hauke Exp $

Upstream interface change: slave -> secondary

--- src/radeon_kms.c.orig	2019-10-15 16:16:29.000000000 +0000
+++ src/radeon_kms.c
@@ -559,8 +559,8 @@ dirty_region(PixmapDirtyUpdatePtr dirty)
 	if (dirty->rotation != RR_Rotate_0) {
 		dstregion = transform_region(damageregion,
 					     &dirty->f_inverse,
-					     dirty->slave_dst->drawable.width,
-					     dirty->slave_dst->drawable.height);
+					     dirty->secondary_dst->drawable.width,
+					     dirty->secondary_dst->drawable.height);
 	} else
 #endif
 	{
@@ -568,7 +568,7 @@ dirty_region(PixmapDirtyUpdatePtr dirty)
 
 	    dstregion = RegionDuplicate(damageregion);
 	    RegionTranslate(dstregion, -dirty->x, -dirty->y);
-	    PixmapRegionInit(&pixregion, dirty->slave_dst);
+	    PixmapRegionInit(&pixregion, dirty->secondary_dst);
 	    RegionIntersect(dstregion, dstregion, &pixregion);
 	    RegionUninit(&pixregion);
 	}
@@ -585,8 +585,8 @@ redisplay_dirty(PixmapDirtyUpdatePtr dir
 	if (RegionNil(region))
 		goto out;
 
-	if (dirty->slave_dst->master_pixmap)
-	    DamageRegionAppend(&dirty->slave_dst->drawable, region);
+	if (dirty->secondary_dst->primary_pixmap)
+	    DamageRegionAppend(&dirty->secondary_dst->drawable, region);
 
 #ifdef HAS_DIRTYTRACKING_ROTATION
 	PixmapSyncDirtyHelper(dirty);
@@ -595,8 +595,8 @@ redisplay_dirty(PixmapDirtyUpdatePtr dir
 #endif
 
 	radeon_cs_flush_indirect(src_scrn);
-	if (dirty->slave_dst->master_pixmap)
-	    DamageRegionProcessPending(&dirty->slave_dst->drawable);
+	if (dirty->secondary_dst->primary_pixmap)
+	    DamageRegionProcessPending(&dirty->secondary_dst->drawable);
 
 out:
 	DamageEmpty(dirty->damage);
@@ -618,7 +618,7 @@ radeon_sync_shared_pixmap(PixmapDirtyUpd
     RegionPtr region;
 
     xorg_list_for_each_entry(ent, &master_screen->pixmap_dirty_list, ent) {
-	if (!radeon_dirty_src_equals(dirty, ent->slave_dst))
+	if (!radeon_dirty_src_equals(dirty, ent->secondary_dst))
 	    continue;
 
 	region = dirty_region(ent);
@@ -641,7 +641,7 @@ master_has_sync_shared_pixmap(ScrnInfoPt
 static Bool
 slave_has_sync_shared_pixmap(ScrnInfoPtr scrn, PixmapDirtyUpdatePtr dirty)
 {
-    ScreenPtr slave_screen = dirty->slave_dst->drawable.pScreen;
+    ScreenPtr slave_screen = dirty->secondary_dst->drawable.pScreen;
 
     return !!slave_screen->SyncSharedPixmap;
 }
@@ -667,7 +667,7 @@ master_has_sync_shared_pixmap(ScrnInfoPt
 static Bool
 slave_has_sync_shared_pixmap(ScrnInfoPtr scrn, PixmapDirtyUpdatePtr dirty)
 {
-    ScrnInfoPtr slave_scrn = xf86ScreenToScrn(dirty->slave_dst->drawable.pScreen);
+    ScrnInfoPtr slave_scrn = xf86ScreenToScrn(dirty->secondary_dst->drawable.pScreen);
 
     return slave_scrn->driverName == scrn->driverName;
 }
@@ -684,7 +684,7 @@ call_sync_shared_pixmap(PixmapDirtyUpdat
 static xf86CrtcPtr
 radeon_prime_dirty_to_crtc(PixmapDirtyUpdatePtr dirty)
 {
-    ScreenPtr screen = dirty->slave_dst->drawable.pScreen;
+    ScreenPtr screen = dirty->secondary_dst->drawable.pScreen;
     ScrnInfoPtr scrn = xf86ScreenToScrn(screen);
     xf86CrtcConfigPtr xf86_config = XF86_CRTC_CONFIG_PTR(scrn);
     int c;
@@ -727,7 +727,7 @@ radeon_prime_scanout_do_update(xf86CrtcP
 		radeon_cs_flush_indirect(scrn);
 		RegionCopy(&drmmode_crtc->scanout_last_region, region);
 		RegionTranslate(region, -crtc->x, -crtc->y);
-		dirty->slave_dst = drmmode_crtc->scanout[scanout_id].pixmap;
+		dirty->secondary_dst = drmmode_crtc->scanout[scanout_id].pixmap;
 	    }
 
 	    redisplay_dirty(dirty, region);
@@ -754,7 +754,7 @@ radeon_prime_scanout_update_handler(xf86
 static void
 radeon_prime_scanout_update(PixmapDirtyUpdatePtr dirty)
 {
-    ScreenPtr screen = dirty->slave_dst->drawable.pScreen;
+    ScreenPtr screen = dirty->secondary_dst->drawable.pScreen;
     ScrnInfoPtr scrn = xf86ScreenToScrn(screen);
     RADEONEntPtr pRADEONEnt = RADEONEntPriv(scrn);
     xf86CrtcPtr xf86_crtc = radeon_prime_dirty_to_crtc(dirty);
@@ -818,7 +818,7 @@ radeon_prime_scanout_update(PixmapDirtyU
 static void
 radeon_prime_scanout_flip(PixmapDirtyUpdatePtr ent)
 {
-    ScreenPtr screen = ent->slave_dst->drawable.pScreen;
+    ScreenPtr screen = ent->secondary_dst->drawable.pScreen;
     ScrnInfoPtr scrn = xf86ScreenToScrn(screen);
     RADEONEntPtr pRADEONEnt = RADEONEntPriv(scrn);
     xf86CrtcPtr crtc = radeon_prime_dirty_to_crtc(ent);
@@ -897,7 +897,7 @@ radeon_dirty_update(ScrnInfoPtr scrn)
 				ScreenPtr master_screen = radeon_dirty_master(ent);
 
 				xorg_list_for_each_entry(region_ent, &master_screen->pixmap_dirty_list, ent) {
-					if (radeon_dirty_src_equals(ent, region_ent->slave_dst))
+					if (radeon_dirty_src_equals(ent, region_ent->secondary_dst))
 						break;
 				}
 			}
