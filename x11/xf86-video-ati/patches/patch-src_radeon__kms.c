$NetBSD: patch-src_radeon__kms.c,v 1.1 2015/02/21 11:45:35 tnn Exp $

https://bugs.freedesktop.org/show_bug.cgi?id=47160

--- src/radeon_kms.c.orig	2014-10-02 03:31:27.000000000 +0000
+++ src/radeon_kms.c
@@ -280,7 +280,7 @@ static void
 radeon_dirty_update(ScreenPtr screen)
 {
 	RegionPtr region;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 
 	if (xorg_list_is_empty(&screen->pixmap_dirty_list))
 		return;
