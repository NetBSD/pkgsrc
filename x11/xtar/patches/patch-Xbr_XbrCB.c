$NetBSD: patch-Xbr_XbrCB.c,v 1.2 2022/01/07 13:02:31 nia Exp $

- Fix implicit declaration warnings.

--- Xbr/XbrCB.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ Xbr/XbrCB.c
@@ -19,6 +19,8 @@
  */
 
 #include <Xm/Xm.h>
+#include <stdlib.h>
+#include <stdio.h>
 
 void XbrCBExitApplication(Widget, XtPointer, XtPointer);
 void XbrCBDestroyWidget(Widget, XtPointer, XtPointer);
