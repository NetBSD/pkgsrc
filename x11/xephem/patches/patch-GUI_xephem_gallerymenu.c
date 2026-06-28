$NetBSD: patch-GUI_xephem_gallerymenu.c,v 1.2 2026/06/28 00:51:58 gdt Exp $

Fix ctype(3) UB.  Cherry-picked from https://github.com/XEphem/XEphem/pull/126

--- GUI/xephem/gallerymenu.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ GUI/xephem/gallerymenu.c
@@ -661,7 +661,7 @@ trimws (char *s)
 {
 	char *s0;
 
-	while (isspace(*s))
+	while (isspace((unsigned char)*s))
 	    s++;
 	s0 = s;
 
@@ -670,7 +670,7 @@ trimws (char *s)
 
 	do
 	    *s-- = '\0';
-	while (s >= s0 && isspace(*s));
+	while (s >= s0 && isspace((unsigned char)*s));
 
 	return (s0);
 }
