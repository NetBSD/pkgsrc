$NetBSD: patch-compiler.c,v 1.1 2026/06/27 20:07:53 gdt Exp $

Fix ctype(3) UB.   Taken from https://github.com/XEphem/XEphem/pull/126

--- compiler.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ compiler.c
@@ -212,7 +212,7 @@ next_token ()
 	int tok = ERR;	/* just something illegal */
 	char c;
 
-	while (isspace(c = *cexpr))
+	while (isspace((unsigned char)(c = *cexpr)))
 	    cexpr++;
 	lcexpr = cexpr++;
 
