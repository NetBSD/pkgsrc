$NetBSD: patch-mozilla_widget_gtk_mozgtk_mozgtk.c,v 1.1 2015/01/02 04:26:21 ryoon Exp $

--- mozilla/widget/gtk/mozgtk/mozgtk.c.orig	2014-12-03 06:23:27.000000000 +0000
+++ mozilla/widget/gtk/mozgtk/mozgtk.c
@@ -121,6 +121,7 @@ STUB(gdk_x11_lookup_xdisplay)
 STUB(gdk_x11_screen_get_xscreen)
 STUB(gdk_x11_visual_get_xvisual)
 STUB(gdk_x11_window_lookup_for_display)
+STUB(gdk_x11_window_set_user_time)
 STUB(gdk_x11_xatom_to_atom)
 STUB(gtk_accel_label_new)
 STUB(gtk_alignment_get_type)
