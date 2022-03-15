$NetBSD: patch-src_uxa_intel__display.c,v 1.3 2022/03/15 18:53:42 tnn Exp $

Similar to https://gitlab.freedesktop.org/xorg/driver/xf86-video-intel/-/issues/171

--- src/uxa/intel_display.c.orig	2021-01-15 20:59:05.000000000 +0000
+++ src/uxa/intel_display.c
@@ -1872,7 +1872,7 @@ intel_drm_abort_one(struct intel_drm_que
 void
 intel_drm_abort(ScrnInfoPtr scrn, Bool (*match)(void *data, void *match_data), void *match_data)
 {
-	struct intel_drm_queue *q;
+	struct intel_drm_queue *q = NULL;
 
 	list_for_each_entry(q, &intel_drm_queue, list) {
 		if (match(q->data, match_data)) {
@@ -1888,7 +1888,7 @@ intel_drm_abort(ScrnInfoPtr scrn, Bool (
 void
 intel_drm_abort_seq(ScrnInfoPtr scrn, uint32_t seq)
 {
-	struct intel_drm_queue *q;
+	struct intel_drm_queue *q = NULL;
 
 	list_for_each_entry(q, &intel_drm_queue, list) {
 		if (q->seq == seq) {
@@ -1905,7 +1905,7 @@ intel_drm_abort_seq(ScrnInfoPtr scrn, ui
 static void
 intel_drm_abort_scrn(ScrnInfoPtr scrn)
 {
-	struct intel_drm_queue *q, *tmp;
+	struct intel_drm_queue *q = NULL, *tmp;
 
 	list_for_each_entry_safe(q, tmp, &intel_drm_queue, list) {
 		if (q->scrn == scrn)
@@ -1994,7 +1994,7 @@ static void
 intel_drm_handler(int fd, uint32_t frame, uint32_t sec, uint32_t usec, void *user_ptr)
 {
 	uint32_t user_data = (intptr_t)user_ptr;
-	struct intel_drm_queue *q;
+	struct intel_drm_queue *q = NULL;
 
 	list_for_each_entry(q, &intel_drm_queue, list) {
 		if (q->seq == user_data) {
