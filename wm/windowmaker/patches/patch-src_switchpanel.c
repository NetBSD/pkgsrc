$NetBSD: patch-src_switchpanel.c,v 1.1 2015/10/16 10:42:23 adam Exp $

--- src/switchpanel.c.orig	2015-08-11 18:41:14.000000000 +0000
+++ src/switchpanel.c
@@ -37,6 +37,8 @@
 
 
 #ifdef USE_XSHAPE
+#include <X11/Xlib.h>
+#include <X11/Xutil.h>
 #include <X11/extensions/shape.h>
 #endif
 
