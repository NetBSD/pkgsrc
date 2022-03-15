$NetBSD: patch-src_uxa_intel__batchbuffer.c,v 1.1 2022/03/15 18:53:42 tnn Exp $

Similar to https://gitlab.freedesktop.org/xorg/driver/xf86-video-intel/-/issues/171

--- src/uxa/intel_batchbuffer.c.orig	2021-01-15 20:59:05.000000000 +0000
+++ src/uxa/intel_batchbuffer.c
@@ -142,7 +142,7 @@ void intel_batch_teardown(ScrnInfoPtr sc
 static void intel_batch_do_flush(ScrnInfoPtr scrn)
 {
 	intel_screen_private *intel = intel_get_screen_private(scrn);
-	struct intel_uxa_pixmap *priv;
+	struct intel_uxa_pixmap *priv = NULL;
 
 	list_for_each_entry(priv, &intel->batch_pixmaps, batch)
 		priv->dirty = 0;
