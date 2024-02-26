$NetBSD: patch-gtk_gtkpathbar.c,v 1.1 2024/02/26 15:05:21 tsutsui Exp $

- pull fixes to avoid gimp errors with recent GLib.
 https://gitlab.gnome.org/GNOME/gimp/-/issues/9994
 https://gitlab.gnome.org/GNOME/gimp/-/commit/024e3c7495bc3f33cf53410c4997201c3f1ab760

--- gtk/gtkpathbar.c.orig	2020-12-18 05:29:40.000000000 +0000
+++ gtk/gtkpathbar.c
@@ -1659,7 +1659,8 @@ gtk_path_bar_get_info_callback (GCancell
     }
 
   display_name = g_file_info_get_display_name (info);
-  is_hidden = g_file_info_get_is_hidden (info) || g_file_info_get_is_backup (info);
+  is_hidden = g_file_info_get_attribute_boolean (info, "standard::is-hidden") ||
+              g_file_info_get_attribute_boolean (info, "standard::is-backup");
 
   gtk_widget_push_composite_child ();
   button_data = make_directory_button (file_info->path_bar, display_name,
