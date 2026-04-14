$NetBSD: patch-slave.c,v 1.1 2026/04/14 12:11:49 kikadf Exp $

* Fix ctype usage

--- slave.c.orig	2026-02-06 09:11:40.270730099 +0000
+++ slave.c
@@ -108,11 +108,11 @@ is_valid_shell(const char *shell)
 
         char *line = _line;
         {
-            while (isspace(*line))
+            while (isspace((unsigned char)*line))
                 line++;
             if (line[0] != '\0') {
                 char *end = line + strlen(line) - 1;
-                while (isspace(*end))
+                while (isspace((unsigned char)*end))
                     end--;
                 *(end + 1) = '\0';
             }
