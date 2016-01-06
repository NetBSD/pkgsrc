$NetBSD: patch-src_radeon__kms.c,v 1.2 2016/01/06 14:53:04 wiz Exp $

Should be fixed by xserver commit:
http://cgit.freedesktop.org/xorg/xserver/commit/?id=63f83d1b7f496d05b409352749cdb6674d71cf80
so patch can be removed once this is in pkgsrc modular-xorg-server.

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
