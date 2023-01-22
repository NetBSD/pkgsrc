$NetBSD: patch-dtools_xtmShowToDo.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Avoid int to pointer conversion warnings.

--- dtools/xtmShowToDo.c.orig	1997-05-04 21:26:20.000000000 +0000
+++ dtools/xtmShowToDo.c
@@ -37,6 +37,7 @@ static char SCCSID[] = "@(#) Module: xtm
 
 #include <string.h>
 #include <stdlib.h>
+#include <stdint.h>
 #include <stdio.h>
 
 #include <X11/Intrinsic.h>
@@ -665,10 +666,10 @@ static Widget
 
     if( XmIsPushButton( menuCtrlBu[ index ] ) )
       XtAddCallback( menuCtrlBu[ index ], XmNactivateCallback, 
-                     (XtCallbackProc) ctrlMenuCB, (XtPointer) index );
+                     (XtCallbackProc) ctrlMenuCB, (XtPointer)(intptr_t)index );
     else if( XmIsToggleButton( menuCtrlBu[ index ] ) )
       XtAddCallback( menuCtrlBu[ index ], XmNvalueChangedCallback, 
-                     (XtCallbackProc) ctrlMenuCB, (XtPointer) index );
+                     (XtCallbackProc) ctrlMenuCB, (XtPointer)(intptr_t)index );
   }
 
 
@@ -681,7 +682,7 @@ static Widget
                                                    &help_casc[ index ] );
 
     XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) infoCB, (XtPointer) index );
+                   (XtCallbackProc) infoCB, (XtPointer)(intptr_t)index );
   }
 
   /* We can't do context sensitive help. */
@@ -1189,7 +1190,7 @@ static void
   custom_data_ref = show_ref -> appl_data_ref -> custom_data;
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Display entry flags? */
     case 0:
@@ -1402,7 +1403,7 @@ static void
   /* Code. */
 
   xtmHlDisplayHelp( show_ref -> appl_data_ref -> info_handle,
-                    (int) call_data -> data,
+                    (intptr_t) call_data -> data,
                     sum_window_id, "" );
 
   return;
