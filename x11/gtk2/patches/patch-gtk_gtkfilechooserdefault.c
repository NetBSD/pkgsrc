$NetBSD: patch-gtk_gtkfilechooserdefault.c,v 1.1 2024/02/26 15:05:21 tsutsui Exp $

- pull fixes to avoid gimp errors with recent GLib.
 https://gitlab.gnome.org/GNOME/gimp/-/issues/9994
 https://gitlab.gnome.org/GNOME/gimp/-/commit/024e3c7495bc3f33cf53410c4997201c3f1ab760

--- gtk/gtkfilechooserdefault.c.orig	2020-12-18 05:50:58.000000000 +0000
+++ gtk/gtkfilechooserdefault.c
@@ -6378,10 +6378,12 @@ show_and_select_files (GtkFileChooserDef
       if (!_gtk_file_system_model_iter_is_visible (fsmodel, &iter))
         {
           GFileInfo *info = _gtk_file_system_model_get_info (fsmodel, &iter);
+          gboolean has_is_hidden = g_file_info_has_attribute (info, "standard::is-hidden");
+          gboolean has_is_backup = g_file_info_has_attribute (info, "standard::is-backup");
 
           if (!enabled_hidden &&
-              (g_file_info_get_is_hidden (info) ||
-               g_file_info_get_is_backup (info)))
+              ((has_is_hidden && g_file_info_get_is_hidden (info)) ||
+               (has_is_backup && g_file_info_get_is_backup (info))))
             {
               g_object_set (impl, "show-hidden", TRUE, NULL);
               enabled_hidden = TRUE;
