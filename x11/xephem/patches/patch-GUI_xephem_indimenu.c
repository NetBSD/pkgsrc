$NetBSD: patch-GUI_xephem_indimenu.c,v 1.1 2026/06/28 00:44:25 gdt Exp $

--- GUI/xephem/indimenu.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ GUI/xephem/indimenu.c
@@ -2520,7 +2520,7 @@ handleOneBLOB (XMLEle *root, IBLOB *bp, 
 
 	/* rig up a file name from the timestamp and format */
 	for (i = 0, tsp = bvp->timestamp; *tsp != '\0'; tsp++)
-	    if (isdigit(*tsp))
+	    if (isdigit((unsigned char)*tsp))
 		fn[i++] = *tsp;
 	fn[i] = '\0';
 	strcat (fn, bp->format);
