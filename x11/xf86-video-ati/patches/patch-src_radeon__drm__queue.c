$NetBSD: patch-src_radeon__drm__queue.c,v 1.2 2016/01/06 14:53:04 wiz Exp $

Fix use of uninitialized pointers. Fixes Xorg SEGV when compiled with clang.

Fixed upstream in xserver instead, see
http://cgit.freedesktop.org/xorg/xserver/commit/?id=63f83d1b7f496d05b409352749cdb6674d71cf80
so patch can be removed once this is in pkgsrc modular-xorg-server.

--- src/radeon_drm_queue.c.orig	2015-11-12 02:57:33.000000000 +0000
+++ src/radeon_drm_queue.c
@@ -59,7 +59,7 @@ radeon_drm_queue_handler(int fd, unsigne
 			 unsigned int usec, void *user_ptr)
 {
 	struct radeon_drm_queue_entry *user_data = user_ptr;
-	struct radeon_drm_queue_entry *e, *tmp;
+	struct radeon_drm_queue_entry *e = NULL, *tmp;
 
 	xorg_list_for_each_entry_safe(e, tmp, &radeon_drm_queue, list) {
 		if (e == user_data) {
@@ -119,7 +119,7 @@ radeon_drm_abort_one(struct radeon_drm_q
 void
 radeon_drm_abort_client(ClientPtr client)
 {
-    struct radeon_drm_queue_entry *e, *tmp;
+    struct radeon_drm_queue_entry *e = NULL, *tmp;
 
     xorg_list_for_each_entry_safe(e, tmp, &radeon_drm_queue, list) {
 	if (e->client == client)
@@ -142,7 +142,7 @@ radeon_drm_abort_entry(struct radeon_drm
 void
 radeon_drm_abort_id(uint64_t id)
 {
-    struct radeon_drm_queue_entry *e, *tmp;
+    struct radeon_drm_queue_entry *e = NULL, *tmp;
 
     xorg_list_for_each_entry_safe(e, tmp, &radeon_drm_queue, list) {
 	if (e->id == id) {
@@ -170,7 +170,7 @@ radeon_drm_queue_init()
 void
 radeon_drm_queue_close(ScrnInfoPtr scrn)
 {
-    struct radeon_drm_queue_entry *e, *tmp;
+    struct radeon_drm_queue_entry *e = NULL, *tmp;
 
     xorg_list_for_each_entry_safe(e, tmp, &radeon_drm_queue, list) {
 	if (e->scrn == scrn)
