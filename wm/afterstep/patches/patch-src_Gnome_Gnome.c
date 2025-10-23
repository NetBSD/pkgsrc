$NetBSD: patch-src_Gnome_Gnome.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- src/Gnome/Gnome.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/Gnome/Gnome.c
@@ -1194,7 +1194,7 @@ parse_config (char *cfgfile)
 
   while ((tline = fgets (line, MAXLINELENGTH, ptr)) != NULL)
     {
-      while (isspace (*tline))
+      while (isspace ((unsigned char)*tline))
 	tline++;
       if ((*tline == '*') && (!mystrncasecmp (tline + 1, MyName, len)))
 	{
