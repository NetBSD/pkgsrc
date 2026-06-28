$NetBSD: patch-GUI_xephem_skyip.c,v 1.2 2026/06/28 00:51:58 gdt Exp $

Fix ctype(3) UB.  Cherry-picked from https://github.com/XEphem/XEphem/pull/126

--- GUI/xephem/skyip.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ GUI/xephem/skyip.c
@@ -2573,8 +2573,8 @@ char msg[];
 
 	/* relax need for user to type in upper case */
 	for (bp = kw; *bp; bp++)
-	    if (islower(*bp))
-		*bp = toupper(*bp);
+	    if (islower((unsigned char)*bp))
+		*bp = toupper((unsigned char)*bp);
 
 	/* get from FITS header and copy to our value field */
 	if (getStringFITS (&fim, kw, valu) == 0) {
