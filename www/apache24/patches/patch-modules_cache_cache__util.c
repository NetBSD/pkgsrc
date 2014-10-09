$NetBSD: patch-modules_cache_cache__util.c,v 1.1.2.2 2014/10/09 13:45:27 tron Exp $

Fix for CVE-2014-3581 - Avoid a crash when Content-Type has an empty value.

--- modules/cache/cache_util.c.orig	2014-05-30 13:50:37.000000000 +0000
+++ modules/cache/cache_util.c
@@ -1258,8 +1258,10 @@ apr_table_t *cache_merge_headers_out(req
 
     if (r->content_type
             && !apr_table_get(headers_out, "Content-Type")) {
-        apr_table_setn(headers_out, "Content-Type",
-                       ap_make_content_type(r, r->content_type));
+        const char *ctype = ap_make_content_type(r, r->content_type);
+        if (ctype) {
+            apr_table_setn(headers_out, "Content-Type", ctype);
+        }
     }
 
     if (r->content_encoding
