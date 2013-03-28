$NetBSD: patch-winpinmenu.c,v 1.1 2013/03/28 21:40:12 joerg Exp $

--- winpinmenu.c.orig	2013-03-28 19:48:07.000000000 +0000
+++ winpinmenu.c
@@ -84,11 +84,8 @@ afterMenuShow(win)
 /* 
  * eventButtonPress  - a button has gone down.
  */
-static int
-eventButtonPress(dpy, event, winInfo)
-    Display		*dpy;
-    XEvent		*event;
-    WinPinMenu		*winInfo;
+static void
+eventButtonPress(Display *dpy, XEvent *event, WinPinMenu *winInfo)
 {
     if (! StartMenuGrabs(dpy, winInfo))
 	return;
@@ -99,11 +96,8 @@ eventButtonPress(dpy, event, winInfo)
 }
 
 
-static int
-eventKeyEvent(dpy, event, winInfo)
-    Display		*dpy;
-    XEvent		*event;
-    WinPinMenu		*winInfo;
+static void
+eventKeyEvent(Display *dpy, XEvent *event, WinPinMenu *winInfo)
 {
     MenuMakeFirst(winInfo->menuInfo, afterMenuShow, winInfo);
 
