$NetBSD: patch-mozilla_widget_gtk_gtkdrawing.h,v 1.1 2015/01/02 04:26:21 ryoon Exp $

--- mozilla/widget/gtk/gtkdrawing.h.orig	2014-12-03 06:23:27.000000000 +0000
+++ mozilla/widget/gtk/gtkdrawing.h
@@ -259,6 +259,19 @@ gint moz_gtk_get_widget_border(GtkThemeW
                                gboolean inhtml);
 
 /**
+ * Get the border size of a notebook tab
+ * left/right:  [OUT] the tab's left/right border
+ * top/bottom:  [OUT] the tab's top/bottom border
+ * direction:   the text direction for the widget
+ * flags:       tab-dependant flags; see the GtkTabFlags definition.
+ *
+ * returns:    MOZ_GTK_SUCCESS if there was no error, an error code otherwise
+ */
+gint
+moz_gtk_get_tab_border(gint* left, gint* top, gint* right, gint* bottom, 
+                       GtkTextDirection direction, GtkTabFlags flags);
+
+/**
  * Get the desired size of a GtkCheckButton
  * indicator_size:     [OUT] the indicator size
  * indicator_spacing:  [OUT] the spacing between the indicator and its
