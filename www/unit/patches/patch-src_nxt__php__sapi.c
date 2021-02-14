$NetBSD: patch-src_nxt__php__sapi.c,v 1.1 2021/02/14 11:56:57 otis Exp $

Use correct type.

--- src/nxt_php_sapi.c.orig	2021-02-04 15:22:33.000000000 +0000
+++ src/nxt_php_sapi.c
@@ -1191,7 +1191,7 @@ nxt_php_send_headers(sapi_headers_struct
         }
 
         value = colon + 1;
-        while(isspace(*value)) {
+        while(isspace((unsigned char)(*value))) {
             value++;
         }
 
