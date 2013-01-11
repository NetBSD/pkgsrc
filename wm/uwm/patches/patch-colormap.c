$NetBSD: patch-colormap.c,v 1.1 2013/01/11 23:36:16 joerg Exp $

--- colormap.c.orig	2013-01-11 14:56:26.000000000 +0000
+++ colormap.c
@@ -4,6 +4,8 @@
 
 # include "uwm.h"
 
+static void installColormap (Colormap colormap);
+
 Bool	focusPointerRoot;
 
 Window
@@ -299,8 +301,7 @@ noteUninstalledColormap (colormap)
 	XInstallColormap (dpy, colormap);
 }
 
-installColormap (colormap)
-    Colormap	colormap;
+static void installColormap (Colormap colormap)
 {
     struct colormapInfo	*ci;
 
