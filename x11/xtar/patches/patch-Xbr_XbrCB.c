$NetBSD: patch-Xbr_XbrCB.c,v 1.1 2022/01/07 12:43:14 nia Exp $

- Fix implicit declaration warnings.

--- Xbr/XbrCB.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ Xbr/XbrCB.c
@@ -19,6 +19,7 @@
  */
 
 #include <Xm/Xm.h>
+#include <stdlib.h>
 
 void XbrCBExitApplication(Widget, XtPointer, XtPointer);
 void XbrCBDestroyWidget(Widget, XtPointer, XtPointer);
