$NetBSD: patch-src_sna_sna__damage.c,v 1.1 2022/03/15 18:53:42 tnn Exp $

https://gitlab.freedesktop.org/xorg/driver/xf86-video-intel/-/issues/171
https://gitlab.freedesktop.org/E5ten/xf86-video-intel/-/commit/a92ccaf05efe8f11b3c5cd217d48ad3cf4caa090

--- src/sna/sna_damage.c.orig	2021-01-15 20:59:05.000000000 +0000
+++ src/sna/sna_damage.c
@@ -215,7 +215,7 @@ static void __sna_damage_reduce(struct s
 	int n, nboxes;
 	BoxPtr boxes, free_boxes = NULL;
 	pixman_region16_t *region = &damage->region;
-	struct sna_damage_box *iter;
+	struct sna_damage_box *iter = NULL;
 
 	assert(damage->mode != DAMAGE_ALL);
 	assert(damage->dirty);
@@ -1808,7 +1808,7 @@ void _sna_damage_debug_get_region(struct
 {
 	int n, nboxes;
 	BoxPtr boxes;
-	struct sna_damage_box *iter;
+	struct sna_damage_box *iter = NULL;
 
 	RegionCopy(r, &damage->region);
 	if (!damage->dirty)
