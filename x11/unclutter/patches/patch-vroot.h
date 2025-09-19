$NetBSD: patch-vroot.h,v 1.1 2025/09/19 06:24:26 mrg Exp $

Port to modern C.

--- vroot.h.orig	1991-08-02 09:13:54.000000000 -0700
+++ vroot.h	2025-09-18 23:13:45.217089016 -0700
@@ -38,8 +38,7 @@
 #include <X11/Xatom.h>
 
 static Window
-VirtualRootWindow(dpy, screen)
-Display *dpy;
+VirtualRootWindow(Display *dpy, int screen)
 {
 	static Display *save_dpy = (Display *)0;
 	static int save_screen = -1;
