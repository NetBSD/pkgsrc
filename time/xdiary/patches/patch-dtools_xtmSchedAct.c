$NetBSD: patch-dtools_xtmSchedAct.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Avoid int to pointer conversion warnings.

--- dtools/xtmSchedAct.c.orig	1997-05-04 21:16:55.000000000 +0000
+++ dtools/xtmSchedAct.c
@@ -37,6 +37,7 @@ static char SCCSID[] = "@(#) Module: xtm
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <stdint.h>
 #include <string.h>
 
 #include <X11/Intrinsic.h>
@@ -1967,7 +1968,7 @@ static Widget
 
     if( XmIsPushButton( menuPopupBu[ index ] ) )
       XtAddCallback( menuPopupBu[ index ], XmNactivateCallback, 
-                     (XtCallbackProc) entryPuMenuCB, (XtPointer) index );
+                     (XtCallbackProc) entryPuMenuCB, (XtPointer)(intptr_t)index );
   }
 
   XtManageChildren( menuPopupBu, XtNumber( menuPopupBu ) );
@@ -2106,7 +2107,7 @@ static void
 
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Edit the entry. */
     case 0:
