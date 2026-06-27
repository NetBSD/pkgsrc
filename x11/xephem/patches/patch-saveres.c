$NetBSD: patch-saveres.c,v 1.1 2026/06/27 20:07:53 gdt Exp $

Fix ctype(3) UB.   Taken from https://github.com/XEphem/XEphem/pull/126

--- saveres.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ saveres.c
@@ -1785,10 +1785,10 @@ char *from;
 {
 	char *lastnwsp;		/* last non w/s char in to not counting '\0' */
 
-	while (isspace(*from))
+	while (isspace((unsigned char)*from))
 	    from++;
 	for (lastnwsp = NULL; (*to = *from) != '\0'; to++, from++)
-	    if (!isspace(*to))
+	    if (!isspace((unsigned char)*to))
 		lastnwsp = to;
 	if (lastnwsp)
 	    *++lastnwsp = '\0';
