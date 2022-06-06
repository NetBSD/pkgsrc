$NetBSD: patch-src_bltConfig.c,v 1.1 2022/06/06 04:27:14 dholland Exp $

Fix ctype abuse.

--- src/bltConfig.c~	2002-09-18 22:30:51.000000000 +0000
+++ src/bltConfig.c
@@ -1255,7 +1255,7 @@ Blt_ConfigureWidgetComponent(interp, par
     tempName = Blt_Strdup(resName);
 
     /* Window name can't start with an upper case letter */
-    tempName[0] = tolower(resName[0]);
+    tempName[0] = tolower((unsigned char)resName[0]);
 
     /*
      * Create component if a child window by the component's name
