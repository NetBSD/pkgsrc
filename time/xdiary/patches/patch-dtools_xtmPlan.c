$NetBSD: patch-dtools_xtmPlan.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Avoid int to pointer conversion warnings.

--- dtools/xtmPlan.c.orig	1997-05-04 21:09:51.000000000 +0000
+++ dtools/xtmPlan.c
@@ -37,6 +37,7 @@ static char SCCSID[] = "@(#) Module: xtm
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <stdint.h>
 #include <string.h>
 #include <time.h>
 #include <ctype.h>
@@ -1004,7 +1005,7 @@ static Widget
 
     if( XmIsPushButton( menuFileBu[ index ] ) )
       XtAddCallback( menuFileBu[ index ], XmNactivateCallback, 
-                     (XtCallbackProc) fileMenuCB, (XtPointer) index );
+                     (XtCallbackProc) fileMenuCB, (XtPointer)(intptr_t)index );
   }
 
   /* Create the control menu. */
@@ -1019,10 +1020,10 @@ static Widget
 
     if( XmIsPushButton( menuCtrlBu[ index ] ) )
       XtAddCallback( menuCtrlBu[ index ], XmNactivateCallback, 
-                     (XtCallbackProc) ctrlMenuCB, (XtPointer) index );
+                     (XtCallbackProc) ctrlMenuCB, (XtPointer)(intptr_t)index );
     else if( XmIsToggleButton( menuCtrlBu[ index ] ) )
       XtAddCallback( menuCtrlBu[ index ], XmNvalueChangedCallback, 
-                     (XtCallbackProc) ctrlMenuCB, (XtPointer) index );
+                     (XtCallbackProc) ctrlMenuCB, (XtPointer)(intptr_t)index );
   }
 
   /* Create the options menu. */
@@ -1035,7 +1036,7 @@ static Widget
 
     if( XmIsPushButton( menuOptBu[ index ] ) )
       XtAddCallback( menuOptBu[ index ], XmNactivateCallback, 
-                     (XtCallbackProc) optMenuCB, (XtPointer) index );
+                     (XtCallbackProc) optMenuCB, (XtPointer)(intptr_t)index );
   }
 
   /* Create the help menu. */
@@ -1048,7 +1049,7 @@ static Widget
 
     if( XmIsPushButton( menuHelpBu[ index ] ) )
       XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                     (XtCallbackProc) infoCB, (XtPointer) index );
+                     (XtCallbackProc) infoCB, (XtPointer)(intptr_t)index );
   }
 
   /* We can't do context sensitive help. */
@@ -3434,7 +3435,7 @@ static void
 
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Instant update. */
     case 0:
@@ -3583,7 +3584,7 @@ static void
 
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Close the window. */
     case 0:
@@ -3609,7 +3610,7 @@ static void
   /* Variables. */
   Boolean                 ok;
   int                     char_read;
-  int                     ref_count;
+  intptr_t                ref_count;
   char                    calendar[ XTM_GL_MAX_CAL_NAME + 1 ];
   char                    *group_name;
   char                    *members_ref;
@@ -3664,7 +3665,7 @@ static void
     XtSetArg( args[ n ], XmNuserData, &user_data_ref ); n++;
     XtGetValues( calW, args, n );
 
-    ref_count = (int) user_data_ref;
+    ref_count = (intptr_t) user_data_ref;
 
     if( call_data -> set ) {
       if( ref_count < 1 ) 
@@ -3710,7 +3711,7 @@ static void
   /* Code. */
 
   /* About window? */
-  if( (int) call_data -> data == 6 ) {
+  if( (intptr_t) call_data -> data == 6 ) {
     xtmHlDisplayAboutWindow( plan_ref -> plannerW );
 
     return;
@@ -3718,7 +3719,7 @@ static void
 
   /* Use the standard help. */
   xtmHlDisplayHelp( plan_ref -> appl_data_ref -> info_handle,
-                    (int) call_data -> data,
+                    (intptr_t) call_data -> data,
                     planner_window_id, "" );
 
   return;
@@ -3810,7 +3811,7 @@ static void
 
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Send message. */
     case 0:
