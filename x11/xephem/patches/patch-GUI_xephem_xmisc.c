$NetBSD: patch-GUI_xephem_xmisc.c,v 1.1 2026/06/28 00:44:25 gdt Exp $

--- GUI/xephem/xmisc.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ GUI/xephem/xmisc.c
@@ -1130,7 +1130,7 @@ strtolower (char *str)
 
 	/* actually faster to /not/ call isupper() first */
 	do
-	    *s = tolower (*s);
+	    *s = tolower ((unsigned char)*s);
 	while (*s++);
 
 	return (str);
