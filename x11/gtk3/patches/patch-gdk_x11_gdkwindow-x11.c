$NetBSD: patch-gdk_x11_gdkwindow-x11.c,v 1.1 2019/01/04 20:54:03 leot Exp $

x11: Fix deprecation macro use

G_GNUC_END_IGNORE_DEPRECATIONS terminates the if statement and does not
consider the following block to be part of the if. So that block was
always taken irregardless of the pattern.

Fixes #1280

From upstream commit:

<https://gitlab.gnome.org/GNOME/gtk/commit/e3a1593a0984cc0156ec1892a46af8f256a64878>

--- gdk/x11/gdkwindow-x11.c.orig	2018-12-12 14:08:44.000000000 +0000
+++ gdk/x11/gdkwindow-x11.c
@@ -2985,6 +2985,7 @@ gdk_window_x11_set_background (GdkWindow
   double r, g, b, a;
   cairo_surface_t *surface;
   cairo_matrix_t matrix;
+  cairo_pattern_t *parent_relative_pattern;
 
   if (GDK_WINDOW_DESTROYED (window))
     return;
@@ -2997,8 +2998,10 @@ gdk_window_x11_set_background (GdkWindow
     }
 
 G_GNUC_BEGIN_IGNORE_DEPRECATIONS
-  if (pattern == gdk_x11_get_parent_relative_pattern ())
+  parent_relative_pattern = gdk_x11_get_parent_relative_pattern ();
 G_GNUC_END_IGNORE_DEPRECATIONS
+
+  if (pattern == parent_relative_pattern)
     {
       GdkWindow *parent;
 
