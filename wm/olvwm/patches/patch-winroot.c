$NetBSD: patch-winroot.c,v 1.1 2013/03/28 21:40:12 joerg Exp $

--- winroot.c.orig	2013-03-28 19:50:18.000000000 +0000
+++ winroot.c
@@ -190,11 +190,8 @@ matchKeystrokeToSpec(event,spec)
  * crossed through the root window into a child window, and we will get the
  * EnterNotify for that child window.
  */
-static int
-eventEnterNotify(dpy, pEvent, winInfo)
-	Display		*dpy;
-	XEvent		*pEvent;
-	WinRoot		*winInfo;
+static void
+eventEnterNotify(Display *dpy, XEvent *pEvent, WinRoot *winInfo)
 {
         if (pEvent->xcrossing.detail == NotifyNonlinearVirtual)
             return;
@@ -282,11 +279,8 @@ selectInBox(dpy, winInfo, boxX, boxY, bo
 /* 
  * eventMotionNotify - the pointer is moving
  */
-static int
-eventMotionNotify(dpy, pEvent, winInfo)
-	Display		*dpy;
-	XEvent		*pEvent;
-	WinRoot		*winInfo;
+static void
+eventMotionNotify(Display *dpy, XEvent *pEvent, WinRoot *winInfo)
 {
 	int			(*selectFunc)();
 
@@ -336,11 +330,8 @@ eventMotionNotify(dpy, pEvent, winInfo)
  * If the user clicks in the window, the focus is set to the no-focus window, 
  * and the PRIMARY and SECONDARY selections are acquired and nulled.
  */
-static int
-eventButtonRelease(dpy, pEvent, winInfo)
-	Display		*dpy;
-	XEvent		*pEvent;
-	WinRoot		*winInfo;
+static void
+eventButtonRelease(Display *dpy, XEvent *pEvent, WinRoot *winInfo)
 {
 	if (!AllButtonsUp(pEvent))
 	    return;
@@ -368,11 +359,8 @@ eventButtonRelease(dpy, pEvent, winInfo)
  * or by issuing an AllowEvents request, and (3) ungrab the pointer if the
  * child's handler didn't issue a grab of its own.
  */
-static int
-eventButtonPress(dpy, pEvent, winInfo)
-	Display		*dpy;
-	XEvent		*pEvent;
-	WinRoot		*winInfo;
+static void
+eventButtonPress(Display *dpy, XEvent *pEvent, WinRoot *winInfo)
 {
 	SemanticAction a;
 	WinGeneric *child;
@@ -442,12 +430,9 @@ eventKeyPressRelease(dpy, pEvent, winInf
 /* 
  * eventPropertyNotify - a root property has changed
  */
-static int
+static void
 /* ARGSUSED */
-eventPropertyNotify(dpy, pEvent, winInfo)
-	Display		*dpy;
-	XEvent		*pEvent;
-	WinRoot		*winInfo;
+eventPropertyNotify(Display *dpy, XEvent *pEvent, WinRoot *winInfo)
 {
 	unsigned long	nitems, remain;
 	char		*resourceString;
