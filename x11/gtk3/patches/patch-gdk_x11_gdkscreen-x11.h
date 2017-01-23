$NetBSD: patch-gdk_x11_gdkscreen-x11.h,v 1.1 2017/01/23 13:52:06 maya Exp $

Don't redefine GdkX11Monitor (it's also defined in gdkx11monitor.h:37)

--- gdk/x11/gdkscreen-x11.h.orig	2016-12-30 14:55:56.000000000 +0000
+++ gdk/x11/gdkscreen-x11.h
@@ -29,8 +29,10 @@
 #include <X11/Xlib.h>
 
 G_BEGIN_DECLS
-  
+ 
+#if 0
 typedef struct _GdkX11Monitor GdkX11Monitor;
+#endif
 
 struct _GdkX11Screen
 {
