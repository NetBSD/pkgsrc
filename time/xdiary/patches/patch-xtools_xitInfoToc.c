$NetBSD: patch-xtools_xitInfoToc.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Avoid int to pointer conversion warnings.

--- xtools/xitInfoToc.c.orig	1997-05-04 13:15:28.000000000 +0000
+++ xtools/xitInfoToc.c
@@ -35,6 +35,7 @@ static char SCCSID[] = "@(#) Module: xit
 --  Include files
 ----------------------------------------------------------------------------*/
 
+#include <stdint.h>
 #include <limits.h>
 #include <stdio.h>
 #include <ctype.h>
@@ -355,7 +356,7 @@ static Widget
     gotoBu[ index ] = xitCreatePushButton( gotoRc, &goto_def[ index ] );
 
     XtAddCallback( gotoBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) gotoCB, (XtPointer) index );
+                   (XtCallbackProc) gotoCB, (XtPointer)(intptr_t)index );
   }
 
 
@@ -702,7 +703,7 @@ static void
 
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Next? */
     case 0:
