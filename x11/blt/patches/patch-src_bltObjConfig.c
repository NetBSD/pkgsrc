$NetBSD: patch-src_bltObjConfig.c,v 1.1 2022/06/06 04:27:14 dholland Exp $

Fix ctype abuse.

--- src/bltObjConfig.c~	2002-09-18 22:30:51.000000000 +0000
+++ src/bltObjConfig.c
@@ -2275,7 +2275,7 @@ Blt_ConfigureComponentFromObj(interp, pa
     tmpName = Blt_Strdup(name);
 
     /* Window name can't start with an upper case letter */
-    tmpName[0] = tolower(name[0]);
+    tmpName[0] = tolower((unsigned char)name[0]);
 
     /*
      * Create component if a child window by the component's name
