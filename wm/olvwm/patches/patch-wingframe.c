$NetBSD: patch-wingframe.c,v 1.1 2013/03/28 21:40:12 joerg Exp $

--- wingframe.c.orig	2013-03-28 19:57:02.000000000 +0000
+++ wingframe.c
@@ -275,11 +275,8 @@ int x,y,w,h;
  * GFrameEventButtonRelease -- a button has been released
  *
  */
-int
-GFrameEventButtonRelease(dpy, event, frameInfo)
-Display *dpy;
-XEvent  *event;
-WinGenericFrame *frameInfo;
+void
+GFrameEventButtonRelease(Display *dpy, XEvent *event, WinGenericFrame *frameInfo)
 {
         WinGenericPane	*winPane = (WinGenericPane*)frameInfo->fcore.panewin;
         Client *cli = frameInfo->core.client;
@@ -344,11 +341,8 @@ WinGenericFrame *frameInfo;
 /*
  * GFrameEventMotionNotify -- a button is down and the pointer is moving
  */
-int
-GFrameEventMotionNotify(dpy, event, frameInfo)
-Display *dpy;
-XEvent  *event;
-WinGenericFrame *frameInfo;
+void
+GFrameEventMotionNotify(Display *dpy, XEvent *event, WinGenericFrame *frameInfo)
 {
         /* We get this only after a Select press */
         if (hadSelect == False) /* watch for erroneous motions */
