$NetBSD: patch-gtk_gtkscale.c,v 1.1 2024/03/09 04:17:08 schmonz Exp $

Fix cast, and thus at least the macOS build with clang-1500.3.9.4.

--- gtk/gtkscale.c.orig	2024-03-09 04:11:20.974372762 +0000
+++ gtk/gtkscale.c
@@ -1471,7 +1471,7 @@ gtk_scale_add_mark (GtkScale        *sca
   mark->position = position;
  
   priv->marks = g_slist_insert_sorted_with_data (priv->marks, mark,
-                                                 (GCompareFunc) compare_marks,
+                                                 (GCompareDataFunc) compare_marks,
                                                  GINT_TO_POINTER (
                                                    gtk_range_get_inverted (GTK_RANGE (scale)) 
                                                    ));
