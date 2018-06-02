$NetBSD: patch-panel.cpp,v 1.2 2018/06/02 21:00:03 joerg Exp $

XCreateGC returns a null pointer on failure, not a negative value.

--- panel.cpp.orig	2013-10-01 22:38:05.000000000 +0000
+++ panel.cpp
@@ -48,7 +48,7 @@ Panel::Panel(Display* dpy, int scr, Wind
 		gcm = GCGraphicsExposures;
 		gcv.graphics_exposures = False;
 		WinGC = XCreateGC(Dpy, Win, gcm, &gcv);
-		if (WinGC < 0) {
+		if (!WinGC) {
 			cerr << APPNAME
 				<< ": failed to create pixmap\n.";
 			exit(ERR_EXIT);
