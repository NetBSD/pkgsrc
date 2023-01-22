$NetBSD: patch-xtools_xitColorSel.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Avoid int to pointer conversion warnings.

--- xtools/xitColorSel.c.orig	1997-05-04 13:13:45.000000000 +0000
+++ xtools/xitColorSel.c
@@ -38,6 +38,7 @@ static char SCCSID[] = "@(#) Module: xit
 --  Include files
 ----------------------------------------------------------------------------*/
 
+#include <stdint.h>
 #include <stdio.h>
 
 #include <X11/Intrinsic.h>
@@ -302,7 +303,7 @@ Widget
     XtManageChild( menuPb );
 
     XtAddCallback( menuPb, XmNactivateCallback, 
-                   (XtCallbackProc) menuSelectCB, (XtPointer) index );
+                   (XtCallbackProc) menuSelectCB, (XtPointer)(intptr_t)index );
 
     /* The default color is the first color. */
     if( index == 0 ) {
