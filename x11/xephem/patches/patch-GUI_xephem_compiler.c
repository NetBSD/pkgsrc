$NetBSD: patch-GUI_xephem_compiler.c,v 1.1 2026/06/28 00:44:25 gdt Exp $

--- GUI/xephem/compiler.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ GUI/xephem/compiler.c
@@ -212,7 +212,7 @@ next_token ()
 	int tok = ERR;	/* just something illegal */
 	char c;
 
-	while (isspace(c = *cexpr))
+	while (isspace((unsigned char)(c = *cexpr)))
 	    cexpr++;
 	lcexpr = cexpr++;
 
