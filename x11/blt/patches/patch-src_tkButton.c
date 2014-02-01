$NetBSD: patch-src_tkButton.c,v 1.1 2014/02/01 18:12:13 adam Exp $

Fix building with Tcl 8.6.

--- src/tkButton.c.orig	2014-02-01 17:46:04.000000000 +0000
+++ src/tkButton.c
@@ -526,7 +526,7 @@ static int InvokeButton _ANSI_ARGS_((But
 static Blt_TileChangedProc TileChangedProc;
 static Tcl_CmdProc ButtonCmd, LabelCmd, CheckbuttonCmd, RadiobuttonCmd;
 
-EXTERN int TkCopyAndGlobalEval _ANSI_ARGS_((Tcl_Interp *interp, char *script));
+EXTERN int Tcl_EvalEx _ANSI_ARGS_((Tcl_Interp *interp, const char *script, int numBytes, int flags));
 
 #if (TK_MAJOR_VERSION > 4)
 EXTERN void TkComputeAnchor _ANSI_ARGS_((Tk_Anchor anchor, Tk_Window tkwin, 
@@ -1890,7 +1890,7 @@ InvokeButton(butPtr)
 	}
     }
     if ((butPtr->type != TYPE_LABEL) && (butPtr->command != NULL)) {
-	return TkCopyAndGlobalEval(butPtr->interp, butPtr->command);
+	return Tcl_EvalEx(butPtr->interp, butPtr->command, -1, TCL_EVAL_GLOBAL);
     }
     return TCL_OK;
 }
