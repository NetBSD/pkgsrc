$NetBSD: patch-src_bltNsUtil.h,v 1.1 2012/08/21 22:00:24 marino Exp $

--- src/bltNsUtil.h.orig	2002-07-18 06:35:32.000000000 +0000
+++ src/bltNsUtil.h
@@ -47,8 +47,10 @@ typedef struct Tcl_CallFrameStruct *Tcl_
 #endif
 
 
+#if (TCL_MAJOR_VERSION <= 8) && (TCL_MINOR_VERSION < 5)
 EXTERN Tcl_Command Tcl_FindCommand _ANSI_ARGS_((Tcl_Interp *interp,
 	char *name, Tcl_Namespace *nsPtr, int flags));
+#endif
 
 #define NS_SEARCH_NONE		(0)
 #define NS_SEARCH_CURRENT	(1<<0)
@@ -63,7 +65,7 @@ EXTERN Tcl_Namespace *Tcl_GetCurrentName
 
 EXTERN Tcl_Namespace *Tcl_GetGlobalNamespace _ANSI_ARGS_((Tcl_Interp *interp));
 
-#if (TCL_MAJOR_VERSION >= 8)
+#if (TCL_MAJOR_VERSION >= 8) && (TCL_MINOR_VERSION <= 4)
 EXTERN Tcl_Namespace *Tcl_CreateNamespace _ANSI_ARGS_((Tcl_Interp *interp,
 	char *name, ClientData clientData, Tcl_NamespaceDeleteProc *nsDelProc));
 
