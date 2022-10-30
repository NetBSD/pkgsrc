$NetBSD: patch-src_parser.c,v 1.3 2022/10/30 21:58:30 wiedi Exp $

Fixes build on netbsd

--- src/parser.c.orig	2022-09-29 20:27:15.000000000 +0000
+++ src/parser.c
@@ -1360,7 +1360,7 @@ find_xff_host (GLogItem * logitem, char 
   /* if the log format current char is not within the braces special chars, then
    * we assume the range of IPs are within hard delimiters */
   if (!strchr (skips, **p) && strchr (*str, **p)) {
-    strcpy (pch, (char[2]) { (char) **p, '\0' });
+    strcpy (pch, ((char[2]) { (char) **p, '\0' }));
     if (!(extract = parse_string (&(*str), pch, 1)))
       goto clean;
 
