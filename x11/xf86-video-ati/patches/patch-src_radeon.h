$NetBSD: patch-src_radeon.h,v 1.2 2022/07/19 11:59:05 hauke Exp $

Backport upstream commits to fix crash with options NoAccel

Upstream interface change: slave -> secondary, master -> primary

From 4d84cf438e7f1bebf0053035ef0292e9fed257d1 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Michel=20D=C3=A4nzer?= <mdaenzer@redhat.com>
Date: Fri, 29 Nov 2019 16:37:32 +0100
Subject: Handle NULL fb_ptr in pixmap_get_fb

From c0eb5dbd9c1db6b6d5b1574bcd8c584170d7ab54 Mon Sep 17 00:00:00 2001
From: Alexey Sheplyakov <asheplyakov@altlinux.org>
Date: Wed, 27 Nov 2019 20:50:58 +0400
Subject: Don't crash X server if GPU acceleration is not available

--- src/radeon.h.orig	2019-10-15 16:16:29.000000000 +0000
+++ src/radeon.h
@@ -184,8 +184,8 @@ typedef enum {
 static inline ScreenPtr
 radeon_master_screen(ScreenPtr screen)
 {
-    if (screen->current_master)
-	return screen->current_master;
+    if (screen->current_primary)
+	return screen->current_primary;
 
     return screen;
 }
@@ -193,7 +193,7 @@ radeon_master_screen(ScreenPtr screen)
 static inline ScreenPtr
 radeon_dirty_master(PixmapDirtyUpdatePtr dirty)
 {
-    return radeon_master_screen(dirty->slave_dst->drawable.pScreen);
+    return radeon_master_screen(dirty->secondary_dst->drawable.pScreen);
 }
 
 static inline DrawablePtr
@@ -790,8 +790,8 @@ static inline Bool radeon_set_pixmap_bo(
 
 static inline struct radeon_buffer *radeon_get_pixmap_bo(PixmapPtr pPix)
 {
-#ifdef USE_GLAMOR
     RADEONInfoPtr info = RADEONPTR(xf86ScreenToScrn(pPix->drawable.pScreen));
+#ifdef USE_GLAMOR
 
     if (info->use_glamor) {
 	struct radeon_pixmap *priv;
@@ -799,7 +799,7 @@ static inline struct radeon_buffer *rade
 	return priv ? priv->bo : NULL;
     } else
 #endif
-    {
+    if (info->accelOn) {
 	struct radeon_exa_pixmap_priv *driver_priv;
 	driver_priv = exaGetPixmapDriverPrivate(pPix);
 	return driver_priv ? driver_priv->bo : NULL;
@@ -896,7 +896,7 @@ radeon_pixmap_get_fb(PixmapPtr pix)
 				   handle);
     }
 
-    return *fb_ptr;
+    return fb_ptr ? *fb_ptr : NULL;
 }
 
 
