$NetBSD: patch-gtk_gtkfilesystemmodel.c,v 1.1 2024/02/26 15:05:21 tsutsui Exp $

- pull fixes to avoid gimp errors with recent GLib.
 https://gitlab.gnome.org/GNOME/gimp/-/issues/9994
 https://gitlab.gnome.org/GNOME/gimp/-/commit/024e3c7495bc3f33cf53410c4997201c3f1ab760

--- gtk/gtkfilesystemmodel.c.orig	2020-12-18 05:29:40.000000000 +0000
+++ gtk/gtkfilesystemmodel.c
@@ -444,16 +444,22 @@ static gboolean
 node_should_be_visible (GtkFileSystemModel *model, guint id, gboolean filtered_out)
 {
   FileModelNode *node = get_node (model, id);
+  gboolean has_is_hidden, has_is_backup;
   gboolean result;
 
   if (node->info == NULL)
     return FALSE;
 
+  has_is_hidden = g_file_info_has_attribute (node->info, "standard::is-hidden");
+  has_is_backup = g_file_info_has_attribute (node->info, "standard::is-backup");
+
   if (!model->show_hidden &&
-      (g_file_info_get_is_hidden (node->info) || g_file_info_get_is_backup (node->info)))
+      ((has_is_hidden && g_file_info_get_is_hidden (node->info)) ||
+       (has_is_backup && g_file_info_get_is_backup (node->info))))
     return FALSE;
 
-  if (_gtk_file_info_consider_as_directory (node->info))
+   if (_gtk_file_info_consider_as_directory (node->info))
+
     {
       if (!model->show_folders)
         return FALSE;
