$NetBSD: patch-wmzcalock.c,v 1.1.1.1 2010/01/16 11:43:28 sborrill Exp $

--- wmzcalock.c.orig	2000-07-11 18:11:00.000000000 +0100
+++ wmzcalock.c	2010-01-14 16:24:40.000000000 +0000
@@ -645,7 +645,7 @@
 	{
 		gettimeofday(&timeV, NULL);
 		dday = ((float)hour/24)+((float)min/1440)+
-			((float)sec/86400)+((float)timeV.tv_usec/86400000000);
+			((float)sec/86400);
 	}
 
 	switch (tmmode)
@@ -803,7 +803,7 @@
 	{
 		fprintf(stderr,
 			"Warning: Couldn't open file '%s', using font instead\n",pixmap_file);
-		(int *)the_pixmap = NULL;
+		the_pixmap = (Pixmap)NULL;
 	}
 	else
 	{
