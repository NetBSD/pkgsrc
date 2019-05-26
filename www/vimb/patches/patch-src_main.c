$NetBSD: patch-src_main.c,v 1.1 2019/05/26 20:25:13 leot Exp $

Backport upstream commit 79c69ba194db0e4ddfb4ff985bc51c3b14ac8dd3.

Fix segfault on open in new tabe from context menu #556.

--- src/main.c.orig	2019-03-26 22:47:03.000000000 +0000
+++ src/main.c
@@ -1347,17 +1347,22 @@ static void on_webview_load_changed(WebK
         WebKitLoadEvent event, Client *c)
 {
     GTlsCertificateFlags tlsflags;
+    const char *raw_uri;
     char *uri = NULL;
 
+    raw_uri = webkit_web_view_get_uri(webview);
+    if (raw_uri) {
+        uri = util_sanitize_uri(raw_uri);
+    }
+
     switch (event) {
         case WEBKIT_LOAD_STARTED:
 #ifdef FEATURE_AUTOCMD
-            autocmd_run(c, AU_LOAD_STARTED, webkit_web_view_get_uri(webview), NULL);
+            autocmd_run(c, AU_LOAD_STARTED, raw_uri, NULL);
 #endif
             /* update load progress in statusbar */
             c->state.progress = 0;
             vb_statusbar_update(c);
-            uri = util_sanitize_uri(webkit_web_view_get_uri(webview));
             set_title(c, uri);
             /* Make sure hinting is cleared before the new page is loaded.
              * Without that vimb would still be in hinting mode after hinting
@@ -1379,10 +1384,9 @@ static void on_webview_load_changed(WebK
              * right place to remove the flag. */
             c->mode->flags &= ~FLAG_IGNORE_FOCUS;
 #ifdef FEATURE_AUTOCMD
-            autocmd_run(c, AU_LOAD_COMMITTED, webkit_web_view_get_uri(webview), NULL);
+            autocmd_run(c, AU_LOAD_COMMITTED, raw_uri, NULL);
 #endif
             /* save the current URI in register % */
-            uri = util_sanitize_uri(webkit_web_view_get_uri(webview));
             vb_register_add(c, '%', uri);
             /* check if tls is on and the page is trusted */
             if (g_str_has_prefix(uri, "https://")) {
@@ -1405,9 +1409,8 @@ static void on_webview_load_changed(WebK
             break;
 
         case WEBKIT_LOAD_FINISHED:
-            uri = util_sanitize_uri(webkit_web_view_get_uri(webview));
 #ifdef FEATURE_AUTOCMD
-            autocmd_run(c, AU_LOAD_FINISHED, webkit_web_view_get_uri(webview), NULL);
+            autocmd_run(c, AU_LOAD_FINISHED, raw_uri, NULL);
 #endif
             c->state.progress = 100;
             if (strncmp(uri, "about:", 6)) {
