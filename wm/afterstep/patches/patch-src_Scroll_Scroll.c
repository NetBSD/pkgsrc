$NetBSD: patch-src_Scroll_Scroll.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/Scroll/Scroll.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/Scroll/Scroll.c
@@ -166,7 +166,7 @@ ParseOptions (const char *filename)
       len = strlen (MyName);
       while ((tline = fgets (line, MAXLINELENGTH, file)) == NULL)
 	{
-	  while (isspace (*tline))
+	  while (isspace ((unsigned char)*tline))
 	    tline++;
 	  if ((*tline == '*') && (!mystrncasecmp (tline + 1, MyName, len)))
 	    {
