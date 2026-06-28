$NetBSD: patch-GUI_xephem_skyviewmenu.c,v 1.1 2026/06/28 00:44:25 gdt Exp $

--- GUI/xephem/skyviewmenu.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ GUI/xephem/skyviewmenu.c
@@ -9703,7 +9703,7 @@ int d;		/* diam of object we are labelin
 	    if (sv_ggc && chk_greeklabel (name, &gl, &g)) {
 		XTextExtents (sv_gf, &g, 1, &dir, &asc, &des, &xcs);
 		gw = xcs.width;
-		if (isdigit(name[4+gl])) {
+		if (isdigit((unsigned char)name[4+gl])) {
 		    /* don't crowd the superscript */
 		    XTextExtents (sv_pf, name+gl+4, 1, &dir, &asc, &des, &xcs);
 		    gw += 1;
@@ -9802,7 +9802,7 @@ char *gcodep;	/* code to use for drawing
 
 	/* find length of potentionally greek portion */
 	for (gl = 0; ; gl++)
-	    if (!isalpha(name[4+gl]))
+	    if (!isalpha((unsigned char)name[4+gl]))
 		break;
 	if (gl < 2)	/* shortest greek name is 2 chars */
 	    return (0);
