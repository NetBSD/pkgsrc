$NetBSD: patch-src_sna_sna__display.c,v 1.3 2022/03/15 18:53:42 tnn Exp $

https://gitlab.freedesktop.org/xorg/driver/xf86-video-intel/-/issues/171
https://gitlab.freedesktop.org/E5ten/xf86-video-intel/-/commit/a92ccaf05efe8f11b3c5cd217d48ad3cf4caa090

--- src/sna/sna_display.c.orig	2021-01-15 20:59:05.000000000 +0000
+++ src/sna/sna_display.c
@@ -467,7 +467,7 @@ static inline uint32_t fb_id(struct kgem
 
 unsigned sna_crtc_count_sprites(xf86CrtcPtr crtc)
 {
-	struct plane *sprite;
+	struct plane *sprite = NULL;
 	unsigned count;
 
 	count = 0;
@@ -479,7 +479,7 @@ unsigned sna_crtc_count_sprites(xf86Crtc
 
 static struct plane *lookup_sprite(struct sna_crtc *crtc, unsigned idx)
 {
-	struct plane *sprite;
+	struct plane *sprite = NULL;
 
 	list_for_each_entry(sprite, &crtc->sprites, link)
 		if (idx-- == 0)
@@ -1727,7 +1727,7 @@ static bool wait_for_shadow(struct sna *
 
 	if ((flags & MOVE_WRITE) == 0) {
 		if ((flags & __MOVE_SCANOUT) == 0) {
-			struct sna_crtc *crtc;
+			struct sna_crtc *crtc = NULL;
 
 			list_for_each_entry(crtc, &sna->mode.shadow_crtc, shadow_link) {
 				if (overlap(&sna->mode.shadow_region.extents,
@@ -1768,7 +1768,7 @@ static bool wait_for_shadow(struct sna *
 
 	flip_active = sna->mode.flip_active;
 	if (flip_active) {
-		struct sna_crtc *crtc;
+		struct sna_crtc *crtc = NULL;
 		list_for_each_entry(crtc, &sna->mode.shadow_crtc, shadow_link)
 			flip_active -= crtc->flip_pending;
 		DBG(("%s: %d flips still pending, shadow flip_active=%d\n",
@@ -3263,7 +3263,7 @@ static void
 sna_crtc_destroy(xf86CrtcPtr crtc)
 {
 	struct sna_crtc *sna_crtc = to_sna_crtc(crtc);
-	struct plane *sprite, *sn;
+	struct plane *sprite = NULL, *sn;
 
 	if (sna_crtc == NULL)
 		return;
@@ -3652,7 +3652,7 @@ bool sna_has_sprite_format(struct sna *s
 
 	for (i = 0; i < sna->mode.num_real_crtc; i++) {
 		struct sna_crtc *sna_crtc = to_sna_crtc(config->crtc[i]);
-		struct plane *plane;
+		struct plane *plane = NULL;
 
 		list_for_each_entry(plane, &sna_crtc->sprites, link) {
 			struct local_mode_get_plane p;
@@ -8639,7 +8639,7 @@ sna_mode_disable_secondary_planes(struct
 	for (c = 0; c < sna->mode.num_real_crtc; c++) {
 		xf86CrtcPtr crtc = config->crtc[c];
 		struct sna_crtc *sna_crtc = to_sna_crtc(crtc);
-		struct plane *plane;
+		struct plane *plane = NULL;
 
 		list_for_each_entry(plane, &sna_crtc->sprites, link) {
 			struct local_mode_get_plane p;
@@ -8737,7 +8737,7 @@ static bool
 sna_crtc_hide_planes(struct sna *sna, struct sna_crtc *crtc)
 {
 	struct local_mode_set_plane s;
-	struct plane *plane;
+	struct plane *plane = NULL;
 
 	if (crtc->primary.id == 0)
 		return false;
@@ -8774,7 +8774,7 @@ void sna_mode_reset(struct sna *sna)
 
 	for (i = 0; i < sna->mode.num_real_crtc; i++) {
 		struct sna_crtc *sna_crtc = to_sna_crtc(config->crtc[i]);
-		struct plane *plane;
+		struct plane *plane = NULL;
 
 		assert(sna_crtc != NULL);
 
