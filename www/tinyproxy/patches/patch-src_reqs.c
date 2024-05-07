$NetBSD: patch-src_reqs.c,v 1.3 2024/05/07 11:01:43 wiz Exp $

Fix for CVE-2023-49606.
https://github.com/tinyproxy/tinyproxy/commit/12a8484265f7b00591293da492bb3c9987001956

--- src/reqs.c.orig	2022-05-27 14:07:50.000000000 +0000
+++ src/reqs.c
@@ -775,7 +775,7 @@ static int remove_connection_headers (or
         char *data;
         char *ptr;
         ssize_t len;
-        int i;
+        int i,j,df;
 
         for (i = 0; i != (sizeof (headers) / sizeof (char *)); ++i) {
                 /* Look for the connection header.  If it's not found, return. */
@@ -800,7 +800,12 @@ static int remove_connection_headers (or
                  */
                 ptr = data;
                 while (ptr < data + len) {
-                        orderedmap_remove (hashofheaders, ptr);
+                        df = 0;
+                        /* check that ptr isn't one of headers to prevent
+                           double-free (CVE-2023-49606) */
+                        for (j = 0; j != (sizeof (headers) / sizeof (char *)); ++j)
+                                if(!strcasecmp(ptr, headers[j])) df = 1;
+                        if (!df) orderedmap_remove (hashofheaders, ptr);
 
                         /* Advance ptr to the next token */
                         ptr += strlen (ptr) + 1;
