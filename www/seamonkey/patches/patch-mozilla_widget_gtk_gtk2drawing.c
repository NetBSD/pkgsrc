$NetBSD: patch-mozilla_widget_gtk_gtk2drawing.c,v 1.3 2015/09/21 05:03:45 ryoon Exp $

--- mozilla/widget/gtk/gtk2drawing.c.orig	2015-09-02 09:27:33.000000000 +0000
+++ mozilla/widget/gtk/gtk2drawing.c
@@ -831,7 +831,7 @@ moz_gtk_get_focus_outline_size(gint* foc
     return MOZ_GTK_SUCCESS;
 }
 
-gint
+static gint
 moz_gtk_widget_get_focus(GtkWidget* widget, gboolean* interior_focus,
                          gint* focus_width, gint* focus_pad) 
 {
@@ -928,7 +928,7 @@ moz_gtk_splitter_get_metrics(gint orient
     return MOZ_GTK_SUCCESS;
 }
 
-gint
+static gint
 moz_gtk_button_get_inner_border(GtkWidget* widget, GtkBorder* inner_border)
 {
     static const GtkBorder default_inner_border = { 1, 1, 1, 1 };
