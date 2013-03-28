$NetBSD: patch-winipane.c,v 1.1 2013/03/28 21:40:12 joerg Exp $

--- winipane.c.orig	2013-03-28 19:45:55.000000000 +0000
+++ winipane.c
@@ -72,10 +72,8 @@ static ClassPane classIconPane;
  * drawIPane -- draw the pane window
  */
 /*ARGSUSED*/	/* dpy arg will be used when multiple Displays supported */
-static int
-drawIPane(dpy, winInfo)
-Display	*dpy;
-WinIconPane *winInfo;
+static void
+drawIPane(Display *dpy, WinIconPane *winInfo)
 {
     Window 	pane = winInfo->core.self;
     GC 		gc;
