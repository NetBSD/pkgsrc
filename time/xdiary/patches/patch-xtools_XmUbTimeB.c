$NetBSD: patch-xtools_XmUbTimeB.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Avoid int to pointer conversion warnings.

--- xtools/XmUbTimeB.c.orig	1997-05-04 21:09:52.000000000 +0000
+++ xtools/XmUbTimeB.c
@@ -35,6 +35,7 @@ static char SCCSID[] = "@(#) Module: XmU
 --  Include files
 ----------------------------------------------------------------------------*/
 
+#include <stdint.h>
 #include <stdio.h>
 #include <string.h>
 #include <X11/Intrinsic.h>
@@ -2159,7 +2160,7 @@ static void
         /* For predefined actions, call common routine. 
            For other actions, register as callbacks directly. */
         if( ( items[ index ].proc != XmUbTB_NO_ACTION ) &&
-            ( (int) items[ index ].proc <= (int) XmUbTB_LAST_PREDEF_ACTION ) )
+            ( (intptr_t)items[ index ].proc <= (intptr_t)XmUbTB_LAST_PREDEF_ACTION ) )
           XtAddCallback( w, XmNactivateCallback, 
                          (XtCallbackProc) MenuItemActivatedCB, 
                          (XtPointer) items[ index ].proc );
@@ -3366,51 +3367,51 @@ static void
   XtGetValues( pb, args, n );
 
   /* What to do depends on the selected action. */
-  switch( (int) action ){
+  switch((intptr_t)action){
 
-    case (int) XmUbTB_ACTION_THIS_WEEK:
+    case (intptr_t) XmUbTB_ACTION_THIS_WEEK:
       FillInStartOfWeek( tbox );
       AddDateWeek( tbox, 1, 1 );
       break;
 
-    case (int) XmUbTB_ACTION_THIS_MONTH:
+    case (intptr_t) XmUbTB_ACTION_THIS_MONTH:
       FillInStartOfMonth( tbox );
       AddDateMonth( tbox, 1, 1 );
       break;
 
-    case (int) XmUbTB_ACTION_PLUS_ONE_HOUR:
+    case (intptr_t) XmUbTB_ACTION_PLUS_ONE_HOUR:
       AddDateHour( tbox, 1 );
       break;
 
-    case (int) XmUbTB_ACTION_PLUS_TWO_HOURS:
+    case (intptr_t) XmUbTB_ACTION_PLUS_TWO_HOURS:
       AddDateHour( tbox, 2 );
       break;
 
-    case (int) XmUbTB_ACTION_PLUS_ONE_WEEK:
+    case (intptr_t) XmUbTB_ACTION_PLUS_ONE_WEEK:
       AddDateWeek( tbox, 1, 0 );
       break;
 
-    case (int) XmUbTB_ACTION_PLUS_TWO_WEEKS:
+    case (intptr_t) XmUbTB_ACTION_PLUS_TWO_WEEKS:
       AddDateWeek( tbox, 2, 0 );
       break;
 
-    case (int) XmUbTB_ACTION_PLUS_ONE_MONTH:
+    case (intptr_t) XmUbTB_ACTION_PLUS_ONE_MONTH:
       AddDateMonth( tbox, 1, 0 );
       break;
 
-    case (int) XmUbTB_ACTION_TIME_NOW:
+    case (intptr_t) XmUbTB_ACTION_TIME_NOW:
       (void) XmUbTimeBoxSetStartTime( (Widget) tbox, 
                                       TimLocalTime( TimMakeTimeNow() ) );
       range = False;
       break;
 
-    case (int) XmUbTB_ACTION_DATE_NOW:
+    case (intptr_t) XmUbTB_ACTION_DATE_NOW:
       (void) XmUbTimeBoxSetStartDate( (Widget) tbox, 
                                       TimLocalTime( TimMakeTimeNow() ) );
       range = False;
       break;
 
-    case (int) XmUbTB_ACTION_NOW:
+    case (intptr_t) XmUbTB_ACTION_NOW:
       (void) XmUbTimeBoxSetStartDate( (Widget) tbox, 
                                       TimLocalTime( TimMakeTimeNow() ) );
       (void) XmUbTimeBoxSetStartTime( (Widget) tbox, 
@@ -3425,9 +3426,9 @@ static void
   } /* switch */
 
   /* Set the keyboard focus to the most recently inserted text. */
-  switch( (int) action ){
+  switch( (intptr_t) action ){
 
-    case (int) XmUbTB_ACTION_TIME_NOW:
+    case (intptr_t) XmUbTB_ACTION_TIME_NOW:
       /* Set keyboard focus to the start time field. */
       if( tbox -> tbox.internal_children[ XmUbTB_CHILD_START_TIME ] != NULL )
         XmProcessTraversal( 
@@ -3436,7 +3437,7 @@ static void
 
       break;
 
-    case (int) XmUbTB_ACTION_DATE_NOW:
+    case (intptr_t) XmUbTB_ACTION_DATE_NOW:
       /* Set keyboard focus to the start date field. */
       if( tbox -> tbox.internal_children[ XmUbTB_CHILD_START_DATE ] != NULL )
         XmProcessTraversal( 
@@ -3445,7 +3446,7 @@ static void
 
       break;
 
-    case (int) XmUbTB_ACTION_NOW:
+    case (intptr_t) XmUbTB_ACTION_NOW:
       /* Set keyboard focus to the start time or date field. */
       if( tbox -> tbox.internal_children[ XmUbTB_CHILD_START_TIME ] != NULL )
         XmProcessTraversal( 
