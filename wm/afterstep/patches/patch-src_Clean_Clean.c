$NetBSD: patch-src_Clean_Clean.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- src/Clean/Clean.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/Clean/Clean.c
@@ -154,7 +154,7 @@ ParseOptions (const char *filename)
       len = strlen (MyName);
       while (((tline = fgets (line, MAXLINELENGTH, file)) != NULL) && (num_commands < 3))
 	{
-	  while (isspace (*tline))
+	  while (isspace ((unsigned char)*tline))
 	    tline++;
 	  if ((*tline == '*') && (!mystrncasecmp (tline + 1, MyName, len)))
 	    {
@@ -162,11 +162,11 @@ ParseOptions (const char *filename)
 	      sscanf (tline, "%ld", &period[num_commands]);
 	      if (period[num_commands] > maxperiod)
 		maxperiod = period[num_commands];
-	      while (isspace (*tline))
+	      while (isspace ((unsigned char)*tline))
 		tline++;
-	      while ((!isspace (*tline)) && (*tline))
+	      while ((!isspace ((unsigned char)*tline)) && (*tline))
 		tline++;
-	      while (isspace (*tline))
+	      while (isspace ((unsigned char)*tline))
 		tline++;	/* points to "command" field */
 	      strcpy (command[num_commands], tline);
 	      num_commands++;
