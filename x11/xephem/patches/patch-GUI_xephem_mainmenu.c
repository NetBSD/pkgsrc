$NetBSD: patch-GUI_xephem_mainmenu.c,v 1.2 2026/06/28 00:51:58 gdt Exp $

Fix ctype(3) UB.  Cherry-picked from https://github.com/XEphem/XEphem/pull/126

--- GUI/xephem/mainmenu.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ GUI/xephem/mainmenu.c
@@ -2241,7 +2241,7 @@ Field *fp;
 		    char *txt0, *txt;
 
 		    get_xmstring (fp->pb_w, XmNlabelString, &txt0);
-		    for (txt = txt0; *txt && !isdigit(*txt); txt++)
+		    for (txt = txt0; *txt && !isdigit((unsigned char)*txt); txt++)
 			continue;
 		    set_xmstring (prompt_w, XmNtextString, txt);
 		    XtFree (txt0);
