$NetBSD: patch-src_xss-lock.c,v 1.1 2022/11/05 18:13:44 pin Exp $

Avoid core dump when exiting due to loss of X connection.
Fix warning for deprecated declaration.

--- src/xss-lock.c.orig	2014-03-02 10:46:32.000000000 +0000
+++ src/xss-lock.c
@@ -158,9 +158,11 @@ screensaver_event_cb(xcb_connection_t *c
 {
     uint8_t event_type;
     
-    if (!event)
-        g_critical("X connection lost; exiting.");
-    
+    if (!event) {
+        g_info("X connection lost; exiting.");
+        exit(EXIT_FAILURE);
+    }
+
     event_type = XCB_EVENT_RESPONSE_TYPE(event);
     if (event_type == 0) {
         xcb_generic_error_t *error = (xcb_generic_error_t *)event;
@@ -256,7 +258,7 @@ child_watch_cb(GPid pid, gint status, Ch
 #if GLIB_CHECK_VERSION(2, 34, 0)
     GError *error = NULL;
 
-    if (!g_spawn_check_exit_status(status, &error)) {
+    if (!g_spawn_check_wait_status(status, &error)) {
         g_message("%s exited abnormally: %s", child->name, error->message);
         g_error_free(error);
     }
