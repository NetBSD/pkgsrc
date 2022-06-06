$NetBSD: patch-src_bltNsUtil.h,v 1.2 2022/06/06 04:27:14 dholland Exp $

- update version constraints on private decls of tcl functions
  (probably none of these should be here at all as at least some
  of them are unexposed tcl internals)

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
 
@@ -75,7 +77,9 @@ EXTERN Tcl_Namespace *Tcl_FindNamespace 
 EXTERN int Tcl_Export _ANSI_ARGS_((Tcl_Interp *interp, Tcl_Namespace *nsPtr,
 	char *name, int resetFlag));
 
-EXTERN Tcl_Var Tcl_FindNamespaceVar _ANSI_ARGS_((Tcl_Interp *interp, char *name,
+#endif /* TCL_MAJOR_VERSION >= 8 */
+
+EXTERN Tcl_Var Tcl_FindNamespaceVar _ANSI_ARGS_((Tcl_Interp *interp, const char *name,
 	Tcl_Namespace *contextNsPtr, int flags));
 
 EXTERN void Tcl_PopCallFrame _ANSI_ARGS_((Tcl_Interp *interp));
@@ -83,6 +87,8 @@ EXTERN void Tcl_PopCallFrame _ANSI_ARGS_
 EXTERN int Tcl_PushCallFrame _ANSI_ARGS_((Tcl_Interp *interp,
 	Tcl_CallFrame * framePtr, Tcl_Namespace *nsPtr, int isProcCallFrame));
 
+#if (TCL_MAJOR_VERSION >= 8) && (TCL_MINOR_VERSION <= 4)
+
 extern Tcl_HashTable *Blt_GetArrayVariableTable _ANSI_ARGS_((
 	Tcl_Interp *interp, CONST char *varName, int flags));
 
