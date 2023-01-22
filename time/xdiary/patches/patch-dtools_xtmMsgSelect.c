$NetBSD: patch-dtools_xtmMsgSelect.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Avoid int to pointer conversion warnings.

--- dtools/xtmMsgSelect.c.orig	1995-02-18 14:53:48.000000000 +0000
+++ dtools/xtmMsgSelect.c
@@ -37,6 +37,7 @@ static char SCCSID[] = "@(#) Module: xtm
 
 #include <string.h>
 #include <stdlib.h>
+#include <stdint.h>
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -438,7 +439,7 @@ static Widget
                                                    &help_casc[ index ] );
 
     XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) infoCB, (XtPointer) index );
+                   (XtCallbackProc) infoCB, (XtPointer)(intptr_t)index );
   }
 
   /* We can't do context sensitive help. */
@@ -849,7 +850,7 @@ static void
   /* Code. */
 
   xtmHlDisplayHelp( sel_ref -> appl_data_ref -> info_handle,
-                    (int) call_data -> data,
+                    (intptr_t) call_data -> data,
                     select_window_id, "" );
 
   return;
