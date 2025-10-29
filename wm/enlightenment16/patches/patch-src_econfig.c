$NetBSD: patch-src_econfig.c,v 1.1 2025/10/29 23:50:00 gutteridge Exp $

Use ctype.h correctly.

--- src/econfig.c.orig	2025-06-23 13:11:03.000000000 +0000
+++ src/econfig.c
@@ -93,7 +93,7 @@ e16_db_open_read(const char *name)
         /* Strip comment and trailing whitespace */
         i = strcspn(s, "#\r\n");
         for (; i > 0; i--)
-            if (!isspace(s[i - 1]))
+            if (!isspace((unsigned char)s[i - 1]))
                 break;
         s[i] = '\0';
 
