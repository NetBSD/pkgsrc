$NetBSD: patch-src_sna_sna__present.c,v 1.1 2022/03/15 18:53:42 tnn Exp $

https://gitlab.freedesktop.org/xorg/driver/xf86-video-intel/-/issues/171
https://gitlab.freedesktop.org/E5ten/xf86-video-intel/-/commit/a92ccaf05efe8f11b3c5cd217d48ad3cf4caa090

--- src/sna/sna_present.c.orig	2021-01-15 20:59:05.000000000 +0000
+++ src/sna/sna_present.c
@@ -376,7 +376,7 @@ sna_present_get_crtc(WindowPtr window)
 static void add_keepalive(struct sna *sna, xf86CrtcPtr crtc, uint64_t msc)
 {
 	struct list *q = sna_crtc_vblank_queue(crtc);
-	struct sna_present_event *info, *tmp;
+	struct sna_present_event *info, *tmp = NULL;
 	union drm_wait_vblank vbl;
 
 	list_for_each_entry(tmp, q, link) {
@@ -480,7 +480,7 @@ static int
 sna_present_queue_vblank(RRCrtcPtr crtc, uint64_t event_id, uint64_t msc)
 {
 	struct sna *sna = to_sna_from_screen(crtc->pScreen);
-	struct sna_present_event *info, *tmp;
+	struct sna_present_event *info, *tmp = NULL;
 	const struct ust_msc *swap;
 	struct list *q;
 
