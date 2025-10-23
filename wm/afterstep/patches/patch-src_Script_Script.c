$NetBSD: patch-src_Script_Script.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/Script/Script.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/Script/Script.c
@@ -146,7 +146,7 @@ ParseOptions (char *filename)
   Clength = strlen (MyName);
   while (tline != (char *) 0)
     {
-      while (isspace (*tline))
+      while (isspace ((unsigned char)*tline))
 	tline++;
       if ((strlen (&tline[0]) > 1) && (mystrncasecmp (tline, "PixmapPath", 10) == 0))
     pixmapPath = stripcpy(&tline[10]);
