$NetBSD: patch-dtools_xtmPrEntries.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Avoid int to pointer conversion warnings.

--- dtools/xtmPrEntries.c.orig	1997-05-04 21:09:51.000000000 +0000
+++ dtools/xtmPrEntries.c
@@ -37,6 +37,7 @@ static char SCCSID[] = "@(#) Module: xtm
 
 #include <string.h>
 #include <stdlib.h>
+#include <stdint.h>
 #include <stdio.h>
 #include <ctype.h>
 #include <sys/types.h>
@@ -778,10 +779,10 @@ static Widget
 
     if( XmIsPushButton( menuCtrlBu[ index ] ) )
       XtAddCallback( menuCtrlBu[ index ], XmNactivateCallback, 
-                     (XtCallbackProc) ctrlMenuCB, (XtPointer) index );
+                     (XtCallbackProc) ctrlMenuCB, (XtPointer)(intptr_t)index );
     else if( XmIsToggleButton( menuCtrlBu[ index ] ) )
       XtAddCallback( menuCtrlBu[ index ], XmNvalueChangedCallback, 
-                     (XtCallbackProc) ctrlMenuCB, (XtPointer) index );
+                     (XtCallbackProc) ctrlMenuCB, (XtPointer)(intptr_t)index );
   }
 
   /* Create the help menu. */
@@ -793,7 +794,7 @@ static Widget
                                                    &help_casc[ index ] );
 
     XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) infoCB, (XtPointer) index );
+                   (XtCallbackProc) infoCB, (XtPointer)(intptr_t)index );
   }
 
   /* We can't do context sensitive help. */
@@ -1815,7 +1816,7 @@ static void
   custom_data_ref = printer_ref -> appl_data_ref -> custom_data;
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Filter window. */
     case 0:
@@ -2005,7 +2006,7 @@ static void
   /* Code. */
 
   xtmHlDisplayHelp( printer_ref -> appl_data_ref -> info_handle,
-                    (int) call_data -> data,
+                    (intptr_t) call_data -> data,
                     print_window_id, "" );
 
   return;
