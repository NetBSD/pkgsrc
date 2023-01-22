$NetBSD: patch-dtools_xtmEditEntry.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Avoid int to pointer conversion warnings.

--- dtools/xtmEditEntry.c.orig	1997-05-04 22:27:52.000000000 +0000
+++ dtools/xtmEditEntry.c
@@ -38,6 +38,7 @@ static char SCCSID[] = "@(#) Module: xtm
 #include <string.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <stdint.h>
 #include <sys/types.h>
 #include <sys/signal.h>
 #include <sys/stat.h>
@@ -877,7 +878,7 @@ static Widget
                                                    &help_casc[ index ] );
 
     XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) helpCB, (XtPointer) index );
+                   (XtCallbackProc) helpCB, (XtPointer)(intptr_t)index );
   }
 
   /* We can't do context sensitive help. */
@@ -2915,7 +2916,7 @@ static void
   /* Code. */
 
   xtmHlDisplayHelp( editor_ref -> appl_data_ref -> info_handle,
-                    (int) call_data -> data,
+                    (intptr_t) call_data -> data,
                     edit_window_id, "" );
 
   return;
