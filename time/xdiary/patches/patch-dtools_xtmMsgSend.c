$NetBSD: patch-dtools_xtmMsgSend.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Avoid int to pointer conversion warnings.

--- dtools/xtmMsgSend.c.orig	1997-05-04 23:13:08.000000000 +0000
+++ dtools/xtmMsgSend.c
@@ -37,6 +37,7 @@ static char SCCSID[] = "@(#) Module: xtm
 
 #include <string.h>
 #include <stdlib.h>
+#include <stdint.h>
 #include <stdio.h>
 #include <ctype.h>
 
@@ -611,7 +612,7 @@ static Widget
                                                    &help_casc[ index ] );
 
     XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) infoCB, (XtPointer) index );
+                   (XtCallbackProc) infoCB, (XtPointer)(intptr_t)index );
   }
 
   /* We can't do context sensitive help. */
@@ -939,7 +940,7 @@ static Widget
                                                    &help_casc[ index ] );
 
     XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) infoCB, (XtPointer) index );
+                   (XtCallbackProc) infoCB, (XtPointer)(intptr_t)index );
   }
 
   /* We can't do context sensitive help. */
@@ -1811,7 +1812,7 @@ static void
   /* Code. */
 
   xtmHlDisplayHelp( send_ref -> appl_data_ref -> info_handle,
-                    (int) call_data -> data,
+                    (intptr_t) call_data -> data,
                     send_window_id, "" );
 
   return;
