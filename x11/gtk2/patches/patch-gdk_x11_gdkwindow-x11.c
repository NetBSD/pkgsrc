$NetBSD: patch-gdk_x11_gdkwindow-x11.c,v 1.1 2015/04/24 09:50:14 martin Exp $

Avoid alignemnet issues on 64bit machines:
XChangeProperty(... XA_CARDINAL, 32, ...) expects a long* (despite the 32
suggesting otherwise).

--- gdk/x11/gdkwindow-x11.c.orig	2015-04-24 10:58:43.000000000 +0200
+++ gdk/x11/gdkwindow-x11.c	2015-04-24 10:55:15.000000000 +0200
@@ -5575,7 +5575,7 @@
 			gdouble    opacity)
 {
   GdkDisplay *display;
-  guint32 cardinal;
+  long cardinal;
   
   g_return_if_fail (GDK_IS_WINDOW (window));
 
