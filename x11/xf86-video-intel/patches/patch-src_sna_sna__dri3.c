$NetBSD: patch-src_sna_sna__dri3.c,v 1.1 2022/03/15 18:53:42 tnn Exp $

https://gitlab.freedesktop.org/xorg/driver/xf86-video-intel/-/issues/171
https://gitlab.freedesktop.org/E5ten/xf86-video-intel/-/commit/a92ccaf05efe8f11b3c5cd217d48ad3cf4caa090

--- src/sna/sna_dri3.c.orig	2021-01-15 20:59:05.000000000 +0000
+++ src/sna/sna_dri3.c
@@ -175,7 +175,7 @@ static PixmapPtr sna_dri3_pixmap_from_fd
 {
 	struct sna *sna = to_sna_from_screen(screen);
 	PixmapPtr pixmap;
-	struct sna_pixmap *priv;
+	struct sna_pixmap *priv = NULL;
 	struct kgem_bo *bo;
 
 	DBG(("%s(fd=%d, width=%d, height=%d, stride=%d, depth=%d, bpp=%d)\n",
