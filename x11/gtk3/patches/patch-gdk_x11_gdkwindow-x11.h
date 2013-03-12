$NetBSD: patch-gdk_x11_gdkwindow-x11.h,v 1.1 2013/03/12 11:40:25 wiz Exp $

Since libXi-1.7 there are header problems between it and Xfixes-5.0.
This is hacky workaround.

--- gdk/x11/gdkwindow-x11.h.orig	2012-11-19 14:32:20.000000000 +0000
+++ gdk/x11/gdkwindow-x11.h
@@ -25,6 +25,7 @@
 #ifndef __GDK_WINDOW_X11_H__
 #define __GDK_WINDOW_X11_H__
 
+#include <X11/extensions/Xfixes.h>
 #include "gdk/x11/gdkprivate-x11.h"
 #include "gdk/gdkwindowimpl.h"
 
