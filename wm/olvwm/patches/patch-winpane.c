$NetBSD: patch-winpane.c,v 1.1 2013/03/28 21:40:12 joerg Exp $

--- winpane.c.orig	2013-03-28 19:47:39.000000000 +0000
+++ winpane.c
@@ -156,12 +156,9 @@ WinPane	*winInfo;
 /*
  * eventExtension - handle extension events
  */
-static int
+static void
 /* ARGSUSED */
-eventExtension(dpy, event, winInfo)
-    Display	*dpy;
-    XEvent	*event;
-    WinPane	*winInfo;
+eventExtension(Display *dpy, XEvent *event, WinPane *winInfo)
 {
 #ifdef SHAPE
     XShapeEvent *se;
