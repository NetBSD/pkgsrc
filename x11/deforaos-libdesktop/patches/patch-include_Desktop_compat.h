$NetBSD: patch-include_Desktop_compat.h,v 1.1 2016/02/20 02:25:23 khorben Exp $

Fix compatibility layer for Gtk+ 2

--- include/Desktop/compat.h.orig	2015-11-18 21:10:09.000000000 +0000
+++ include/Desktop/compat.h
@@ -103,7 +103,7 @@
 # endif
 
 /* Gtk+ 3.0 */
-# if GTK_CHECK_VERSION(3, 0, 0)
+# if !GTK_CHECK_VERSION(3, 0, 0)
 void gdk_window_clear(GdkWindow * window);
 
 GtkWidget * gtk_box_new(GtkOrientation orientation, gint spacing);
