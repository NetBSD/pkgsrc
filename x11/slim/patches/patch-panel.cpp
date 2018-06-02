$NetBSD: patch-panel.cpp,v 1.1 2018/06/02 16:46:50 jmcneill Exp $

--- panel.cpp.orig	2013-10-01 22:38:05.000000000 +0000
+++ panel.cpp
@@ -48,7 +48,7 @@ Panel::Panel(Display* dpy, int scr, Wind
 		gcm = GCGraphicsExposures;
 		gcv.graphics_exposures = False;
 		WinGC = XCreateGC(Dpy, Win, gcm, &gcv);
-		if (WinGC < 0) {
+		if ((intptr_t)WinGC < 0) {
 			cerr << APPNAME
 				<< ": failed to create pixmap\n.";
 			exit(ERR_EXIT);
