$NetBSD: patch-ical.C,v 1.1 2018/02/18 20:03:31 he Exp $

Use newer API to get interpreter string result.

--- ical.C.orig	2009-04-18 11:49:55.000000000 +0000
+++ ical.C
@@ -141,7 +141,7 @@ void trigger(Tcl_Interp* tcl, char const
     buffer.append('\0');
 
     if (Tcl_Eval(tcl, buffer.as_pointer()) == TCL_ERROR)
-        fprintf(stderr, "ical: trigger error: %s\n", tcl->result);
+        fprintf(stderr, "ical: trigger error: %s\n", Tcl_GetStringResult(tcl));
 
     buffer.clear();
 }
