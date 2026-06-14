$NetBSD: patch-src_bltTreeView.h,v 1.1 2026/06/14 15:46:14 nia Exp $

Declare Blt_TreeViewTextbox to avoid implicit function declarations.

--- src/bltTreeView.h.orig	2026-06-14 15:39:50.798666904 +0000
+++ src/bltTreeView.h
@@ -1100,6 +1100,8 @@ extern int Blt_TreeViewStyleOp _ANSI_ARGS_((TreeView *
 	Blt_TreeNode node));
 extern int Blt_TreeViewStyleOp _ANSI_ARGS_((TreeView *tvPtr, Tcl_Interp *interp,
 	int objc, Tcl_Obj *CONST *objv));
+extern int Blt_TreeViewTextbox _ANSI_ARGS_((TreeView *tvPtr, TreeViewEntry *entryPtr,
+    TreeViewColumn *columnPtr));
 
 #define CHOOSE(default, override)	\
 	(((override) == NULL) ? (default) : (override))
