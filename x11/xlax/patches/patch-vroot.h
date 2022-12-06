$NetBSD: patch-vroot.h,v 1.1 2022/12/06 21:04:14 vins Exp $

Fix compile-time warnings.

--- vroot.h.orig	2008-07-31 20:18:25.000000000 +0000
+++ vroot.h
@@ -75,7 +75,7 @@ VirtualRootWindowOfScreen(screen)
 	if (screen != save_screen) {
 		Display *dpy = DisplayOfScreen(screen);
 		Atom __SWM_VROOT = None;
-		int i;
+		unsigned int i;
 		Window rootReturn, parentReturn, *children;
 		unsigned int numChildren;
 
