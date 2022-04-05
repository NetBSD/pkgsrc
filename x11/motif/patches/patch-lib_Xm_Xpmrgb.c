$NetBSD: patch-lib_Xm_Xpmrgb.c,v 1.1 2022/04/05 09:59:56 riastradh Exp $

Fix ctype(3) abuse.

--- lib/Xm/Xpmrgb.c.orig	2016-03-16 02:10:08.000000000 +0000
+++ lib/Xm/Xpmrgb.c
@@ -99,7 +99,7 @@ xpmReadRgbNames(rgb_fname, rgbn)
 
 	/* Copy string to ascii name and lowercase it. */
 	for (s1 = name, s2 = rgbname; *s1; s1++)
-	    *s2++ = tolower(*s1);
+	    *s2++ = tolower((unsigned char)*s1);
 	*s2 = '\0';
 
 	/* Save the rgb values and ascii name in the array. */
@@ -231,7 +231,7 @@ xpmGetRGBfromName(inname, r, g, b)
     /* fold to lower case */
     p = name;
     while (*p) {
-	*p = tolower(*p);
+	*p = tolower((unsigned char)*p);
 	p++;
     }
 
