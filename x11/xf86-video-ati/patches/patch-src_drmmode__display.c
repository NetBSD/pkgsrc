$NetBSD: patch-src_drmmode__display.c,v 1.1 2022/07/19 11:59:05 hauke Exp $

Upstream interface change: slave -> secondary

--- src/drmmode_display.c.orig	2019-10-15 16:16:29.000000000 +0000
+++ src/drmmode_display.c
@@ -720,7 +720,7 @@ drmmode_crtc_prime_scanout_update(xf86Cr
 		xorg_list_for_each_entry(dirty, &screen->pixmap_dirty_list,
 					 ent) {
 			if (radeon_dirty_src_equals(dirty, drmmode_crtc->prime_scanout_pixmap)) {
-				dirty->slave_dst =
+				dirty->secondary_dst =
 					drmmode_crtc->scanout[scanout_id].pixmap;
 				break;
 			}
@@ -1356,7 +1356,7 @@ drmmode_set_scanout_pixmap(xf86CrtcPtr c
 
 	xorg_list_for_each_entry(dirty, &screen->pixmap_dirty_list, ent) {
 		if (radeon_dirty_src_equals(dirty, drmmode_crtc->prime_scanout_pixmap)) {
-			PixmapStopDirtyTracking(dirty->src, dirty->slave_dst);
+			PixmapStopDirtyTracking(dirty->src, dirty->secondary_dst);
 			break;
 		}
 	}
