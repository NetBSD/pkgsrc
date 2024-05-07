$NetBSD: patch-src_reqs.c,v 1.4 2024/05/07 11:06:27 wiz Exp $

First chunk: fix for CVE-2022-40468 and CVE-2023-40533.
https://github.com/tinyproxy/tinyproxy/commit/3764b8551463b900b5b4e3ec0cd9bb9182191cb7

Chunks 2 & 3: Fix for CVE-2023-49606.
https://github.com/tinyproxy/tinyproxy/commit/12a8484265f7b00591293da492bb3c9987001956

--- src/reqs.c.orig	2022-05-27 14:07:50.000000000 +0000
+++ src/reqs.c
@@ -346,8 +346,12 @@ static struct request_s *process_request
                 goto fail;
         }
 
+        /* zero-terminate the strings so they don't contain junk in error page */
+        request->method[0] = url[0] = request->protocol[0] = 0;
+
         ret = sscanf (connptr->request_line, "%[^ ] %[^ ] %[^ ]",
                       request->method, url, request->protocol);
+
         if (ret == 2 && !strcasecmp (request->method, "GET")) {
                 request->protocol[0] = 0;
 
@@ -775,7 +779,7 @@ static int remove_connection_headers (or
         char *data;
         char *ptr;
         ssize_t len;
-        int i;
+        int i,j,df;
 
         for (i = 0; i != (sizeof (headers) / sizeof (char *)); ++i) {
                 /* Look for the connection header.  If it's not found, return. */
@@ -800,7 +804,12 @@ static int remove_connection_headers (or
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
