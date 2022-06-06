$NetBSD: patch-src_bltInit.c,v 1.1 2022/06/06 04:27:14 dholland Exp $

Pass the right version string to the TCL package calls.
Otherwise, the library fails to initialize.

--- src/bltInit.c~	2022-06-06 01:11:32.563344735 +0000
+++ src/bltInit.c
@@ -415,7 +415,7 @@ Blt_Init(interp)
 	 * Check that the versions of Tcl that have been loaded are
 	 * the same ones that BLT was compiled against.
 	 */
-	if (Tcl_PkgRequire(interp, "Tcl", TCL_VERSION, EXACT) == NULL) {
+	if (Tcl_PkgRequire(interp, "Tcl", TCL_PATCH_LEVEL, EXACT) == NULL) {
 	    return TCL_ERROR;
 	}
 	/* Set the "blt_version", "blt_patchLevel", and "blt_libPath" Tcl
@@ -462,11 +462,11 @@ Blt_Init(interp)
 	Tcl_Namespace *nsPtr;
 
 #if (TCL_VERSION_NUMBER >= _VERSION(8,1,0)) 
-	if (Tcl_PkgPresent(interp, "Tk", TK_VERSION, EXACT) == NULL) {
+	if (Tcl_PkgPresent(interp, "Tk", TK_PATCH_LEVEL, EXACT) == NULL) {
 	    return TCL_OK;
 	} 
 #else
-	if (Tcl_PkgRequire(interp, "Tk", TK_VERSION, EXACT) == NULL) {
+	if (Tcl_PkgRequire(interp, "Tk", TK_PATCH_LEVEL, EXACT) == NULL) {
 	    Tcl_ResetResult(interp);
 	    return TCL_OK;
 	} 
@@ -514,7 +514,7 @@ Blt_Init(interp)
 	 * Check that the versions of Tcl that have been loaded are
 	 * the same ones that BLT was compiled against.
 	 */
-	if (Tcl_PkgRequire(interp, "Tcl", TCL_VERSION, EXACT) == NULL) {
+	if (Tcl_PkgRequire(interp, "Tcl", TCL_PATCH_LEVEL, EXACT) == NULL) {
 	    return TCL_ERROR;
 	}
 	/* Set the "blt_version", "blt_patchLevel", and "blt_libPath" Tcl
@@ -552,11 +552,11 @@ Blt_Init(interp)
 	register Tcl_AppInitProc **p;
 
 #if (TCL_VERSION_NUMBER >= _VERSION(8,1,0)) 
-	if (Tcl_PkgPresent(interp, "Tk", TK_VERSION, EXACT) == NULL) {
+	if (Tcl_PkgPresent(interp, "Tk", TK_PATCH_LEVEL, EXACT) == NULL) {
 	    return TCL_OK;
 	} 
 #else
-	if (Tcl_PkgRequire(interp, "Tk", TK_VERSION, EXACT) == NULL) {
+	if (Tcl_PkgRequire(interp, "Tk", TK_PATCH_LEVEL, EXACT) == NULL) {
 	    Tcl_ResetResult(interp);
 	    return TCL_OK;
 	} 
