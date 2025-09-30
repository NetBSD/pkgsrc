$NetBSD: patch-src_display.c,v 1.1 2025/09/30 14:32:24 gutteridge Exp $

Use ctype.h correctly.

--- src/display.c.orig	2021-12-24 19:22:59.000000000 +0000
+++ src/display.c
@@ -155,7 +155,7 @@ canonical_host (char *host)
     ptr = buf;
     while (*host != 0)
     {
-	*ptr++ = tolower (*host);
+	*ptr++ = tolower ((unsigned char)*host);
 	host++;
     }
     return buf;
