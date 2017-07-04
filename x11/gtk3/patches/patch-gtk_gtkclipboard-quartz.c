$NetBSD: patch-gtk_gtkclipboard-quartz.c,v 1.1 2017/07/04 09:41:09 adam Exp $

Missing function copied from gtk/gtkclipboard.c.

--- gtk/gtkclipboard-quartz.c.orig	2017-07-04 09:03:05.000000000 +0000
+++ gtk/gtkclipboard-quartz.c
@@ -286,6 +286,23 @@ gtk_clipboard_get (GdkAtom selection)
   return gtk_clipboard_get_for_display (gdk_display_get_default (), selection);
 }
 
+/**
+ * gtk_clipboard_get_default:
+ * @display:
+ *
+ * Return value: (transfer none):
+ *
+ * Since: 3.16
+ **/
+GtkClipboard *
+gtk_clipboard_get_default (GdkDisplay *display)
+{
+  g_return_val_if_fail (display != NULL, NULL);
+  g_return_val_if_fail (GDK_IS_DISPLAY (display), NULL);
+
+  return gtk_clipboard_get_for_display (display, GDK_SELECTION_CLIPBOARD);
+}
+
 static void
 clipboard_owner_destroyed (gpointer data)
 {
