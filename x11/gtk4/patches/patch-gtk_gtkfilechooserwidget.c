$NetBSD: patch-gtk_gtkfilechooserwidget.c,v 1.1 2022/08/27 18:16:08 wiz Exp $

GtkFileChooserWidget: Propagate captured key events when the location entry is focused
https://gitlab.gnome.org/GNOME/gtk/-/commit/2b131f09a8403c9ba3d7288901a3c918840df2c3

--- gtk/gtkfilechooserwidget.c.orig	2022-07-02 18:38:25.000000000 +0000
+++ gtk/gtkfilechooserwidget.c
@@ -7763,6 +7763,14 @@ captured_key (GtkEventControllerKey *con
   if (keyval == GDK_KEY_slash)
     return GDK_EVENT_PROPAGATE;
 
+  if (impl->location_entry)
+    {
+      GtkWidget *focus = gtk_root_get_focus (gtk_widget_get_root (GTK_WIDGET (impl)));
+
+      if (focus && gtk_widget_is_ancestor (focus, impl->location_entry))
+        return GDK_EVENT_PROPAGATE;
+    }
+
   handled = gtk_event_controller_key_forward (controller, GTK_WIDGET (impl->search_entry));
   if (handled == GDK_EVENT_STOP)
     operation_mode_set (impl, OPERATION_MODE_SEARCH);
