$NetBSD: patch-winbusy.c,v 1.1 2013/03/28 21:40:12 joerg Exp $

--- winbusy.c.orig	2013-03-28 19:26:50.000000000 +0000
+++ winbusy.c
@@ -30,6 +30,8 @@
 #include "win.h"
 #include "globals.h"
 
+void PaintVirtualWindow(WinGenericFrame *win);
+
 /***************************************************************************
 * global data
 ***************************************************************************/
