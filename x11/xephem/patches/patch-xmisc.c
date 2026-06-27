$NetBSD: patch-xmisc.c,v 1.1 2026/06/27 20:07:53 gdt Exp $

Fix ctype(3) UB.   Taken from https://github.com/XEphem/XEphem/pull/126

--- xmisc.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ xmisc.c
@@ -1130,7 +1130,7 @@ strtolower (char *str)
 
 	/* actually faster to /not/ call isupper() first */
 	do
-	    *s = tolower (*s);
+	    *s = tolower ((unsigned char)*s);
 	while (*s++);
 
 	return (str);
