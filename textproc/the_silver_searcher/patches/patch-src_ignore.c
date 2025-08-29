$NetBSD: patch-src_ignore.c,v 1.1 2025/08/29 12:17:50 leot Exp $

Fix ctype(3) abuses.

--- src/ignore.c.orig	2025-08-29 12:08:03.916286916 +0000
+++ src/ignore.c
@@ -105,7 +105,7 @@ void add_ignore_pattern(ignores *ig, con
 
     /* Kill trailing whitespace */
     for (pattern_len = strlen(pattern); pattern_len > 0; pattern_len--) {
-        if (!isspace(pattern[pattern_len - 1])) {
+        if (!isspace((unsigned char)pattern[pattern_len - 1])) {
             break;
         }
     }
