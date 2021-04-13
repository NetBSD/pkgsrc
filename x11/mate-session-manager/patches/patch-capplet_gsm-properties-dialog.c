$NetBSD: patch-capplet_gsm-properties-dialog.c,v 1.1 2021/04/13 03:22:11 gutteridge Exp $

autostart: fix disabling services in dialog
https://github.com/mate-desktop/mate-session-manager/pull/272

--- capplet/gsm-properties-dialog.c.orig	2021-03-27 10:41:10.000000000 +0000
+++ capplet/gsm-properties-dialog.c
@@ -179,10 +179,6 @@ append_app (GsmPropertiesDialog *dialog,
             GspApp              *app)
 {
         GtkTreeIter   iter;
-        if (find_by_app (GTK_TREE_MODEL (dialog->list_store),
-                         &iter, app)) {
-                return;
-        }
 
         gtk_list_store_append (dialog->list_store, &iter);
         _fill_iter_from_app (dialog->list_store, &iter, app);
@@ -196,7 +192,17 @@ _app_added (GsmPropertiesDialog *dialog,
             GspApp              *app,
             GspAppManager       *manager)
 {
-        append_app (dialog, app);
+        GtkTreeIter   iter;
+        if (find_by_app (GTK_TREE_MODEL (dialog->list_store),
+                         &iter, app)) {
+                return;
+        }
+
+        gtk_list_store_append (dialog->list_store, &iter);
+        _fill_iter_from_app (dialog->list_store, &iter, app);
+
+        g_signal_connect_swapped (app, "changed",
+                                  G_CALLBACK (_app_changed), dialog);
 }
 
 static void
@@ -694,7 +700,6 @@ setup_dialog (GsmPropertiesDialog *dialo
                                   G_CALLBACK (_app_removed), dialog);
 
         populate_model (dialog);
-        update_tree_view (dialog);
 }
 
 static GObject *
