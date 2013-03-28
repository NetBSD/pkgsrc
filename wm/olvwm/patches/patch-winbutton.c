$NetBSD: patch-winbutton.c,v 1.1 2013/03/28 21:40:12 joerg Exp $

--- winbutton.c.orig	2013-03-28 19:29:18.000000000 +0000
+++ winbutton.c
@@ -81,11 +81,8 @@ doUnhilite(act, mode, winInfo)
 /* 
  * eventButtonPress - handle button press events on the close button window.  
  */
-static int
-eventButtonPress(dpy, event, winInfo)
-Display	*dpy;
-XEvent	*event;
-WinButton	*winInfo;
+static void
+eventButtonPress(Display *dpy, XEvent *event, WinButton *winInfo)
 {
 	Client *cli = winInfo->core.client;
 	WinPaneFrame *winFrame = cli->framewin;
@@ -139,11 +136,8 @@ WinButton	*winInfo;
  * stop ignore events.  This is so that double-clicking on the button doesn't
  * close and then reopen the window (or perform the default action twice).
  */
-static int
-eventButtonRelease(dpy, event, winInfo)
-Display	*dpy;
-XEvent	*event;
-WinButton	*winInfo;
+static void
+eventButtonRelease(Display *dpy, XEvent *event, WinButton *winInfo)
 {
 	Client *cli = winInfo->core.client;
 	int x,y;
@@ -187,11 +181,8 @@ WinButton	*winInfo;
 /* 
  * eventMotionNotify - handle motion notify events on the close button window.  
  */
-static int
-eventMotionNotify(dpy, event, winInfo)
-Display	*dpy;
-XEvent	*event;
-WinButton	*winInfo;
+static void
+eventMotionNotify(Display *dpy, XEvent *event, WinButton *winInfo)
 {
 	int 	x,y;
 	Client *cli = winInfo->core.client;
