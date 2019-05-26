$NetBSD: patch-src_util.c,v 1.1 2019/05/26 20:25:13 leot Exp $

Backport upstream commit 79c69ba194db0e4ddfb4ff985bc51c3b14ac8dd3.

Fix segfault on open in new tabe from context menu #556.

--- src/util.c.orig	2019-03-26 22:47:03.000000000 +0000
+++ src/util.c
@@ -821,7 +821,7 @@ char *util_sanitize_filename(char *filen
 /**
  * Strips password from a uri.
  *
- * Return newly allocated string.
+ * Return newly allocated string or NULL.
  */
 char *util_sanitize_uri(const char *uri_str)
 {
@@ -829,6 +829,9 @@ char *util_sanitize_uri(const char *uri_
     char *sanitized_uri;
     char *for_display;
 
+    if (!uri_str) {
+        return NULL;
+    }
 #if WEBKIT_CHECK_VERSION(2, 24, 0)
     for_display = webkit_uri_for_display(uri_str);
 #else
