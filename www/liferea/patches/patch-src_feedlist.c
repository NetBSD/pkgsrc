$NetBSD: patch-src_feedlist.c,v 1.1 2013/03/02 17:53:07 joerg Exp $

--- src/feedlist.c.orig	2013-03-01 13:45:59.000000000 +0000
+++ src/feedlist.c
@@ -381,7 +381,7 @@ on_menu_allfeedsread (GtkWidget *widget,
    problems. Use feedlist_schedule_save() instead! */
 static gboolean feedlist_schedule_save_cb(gpointer user_data) {
 
-	g_return_if_fail(NULL != rootNode);
+	g_return_val_if_fail(NULL != rootNode, FALSE);
 
 	/* step 1: request each node to save its state */
 	feedlist_foreach(node_save);
