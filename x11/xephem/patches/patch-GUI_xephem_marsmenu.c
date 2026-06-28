$NetBSD: patch-GUI_xephem_marsmenu.c,v 1.1 2026/06/28 00:44:25 gdt Exp $

--- GUI/xephem/marsmenu.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ GUI/xephem/marsmenu.c
@@ -998,7 +998,7 @@ m_create_mfform()
 		int j;
 
 		/* widget name is first word in type */
-		for (j = 0; isalpha(mfsp->type[j]); j++)
+		for (j = 0; isalpha((unsigned char)mfsp->type[j]); j++)
 		    buf[j] = mfsp->type[j];
 		buf[j] = '\0';
 
@@ -2222,7 +2222,7 @@ char *name;
 {
 	int l;
 
-	for (l = strlen(name)-1; l >= 0 && isspace(name[l]); --l)
+	for (l = strlen(name)-1; l >= 0 && isspace((unsigned char)name[l]); --l)
 	    name[l] = '\0';
 }
 
