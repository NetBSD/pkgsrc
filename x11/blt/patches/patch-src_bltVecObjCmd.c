$NetBSD: patch-src_bltVecObjCmd.c,v 1.1 2022/06/06 04:27:14 dholland Exp $

Fix ctype misuse.

--- src/bltVecObjCmd.c~	2002-09-14 20:07:43.000000000 +0000
+++ src/bltVecObjCmd.c
@@ -934,7 +934,7 @@ GetBinaryFormat(interp, string, sizePtr)
 {
     char c;
 
-    c = tolower(string[0]);
+    c = tolower((unsigned char)string[0]);
     if (Tcl_GetInt(interp, string + 1, sizePtr) != TCL_OK) {
 	Tcl_AppendResult(interp, "unknown binary format \"", string,
 	    "\": incorrect byte size", (char *)NULL);
