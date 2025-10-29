$NetBSD: patch-src_aclass.c,v 1.1 2025/10/29 23:50:00 gutteridge Exp $

Use ctype.h correctly.

--- src/aclass.c.orig	2025-07-27 07:03:43.000000000 +0000
+++ src/aclass.c
@@ -565,7 +565,7 @@ ActionDecode(const char *line)
     case EVENT_MOUSE_LEAVE:
         if (key[0] == '*')
             anybut = 1;
-        else if (isdigit(key[0]))
+        else if (isdigit((unsigned char)key[0]))
             button = atoi(key);
         if (!anybut && button == 0)
             return NULL;        /* Invalid */
