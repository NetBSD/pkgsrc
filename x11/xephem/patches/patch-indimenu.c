$NetBSD: patch-indimenu.c,v 1.1 2026/06/27 20:07:53 gdt Exp $

Fix ctype(3) UB.   Taken from https://github.com/XEphem/XEphem/pull/126

--- indimenu.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ indimenu.c
@@ -2520,7 +2520,7 @@ handleOneBLOB (XMLEle *root, IBLOB *bp, 
 
 	/* rig up a file name from the timestamp and format */
 	for (i = 0, tsp = bvp->timestamp; *tsp != '\0'; tsp++)
-	    if (isdigit(*tsp))
+	    if (isdigit((unsigned char)*tsp))
 		fn[i++] = *tsp;
 	fn[i] = '\0';
 	strcat (fn, bp->format);
