$NetBSD: patch-src_notification_notif__libnotify.c,v 1.1 2013/08/16 02:37:01 obache Exp $

* for libnotify-0.7 API change

--- src/notification/notif_libnotify.c.orig	2007-09-19 18:38:29.000000000 +0000
+++ src/notification/notif_libnotify.c
@@ -147,7 +147,7 @@ static void notif_libnotify_callback_sho
 //		notify_notification_update ( n, node_get_title(node_p), labelText_now_p, NULL);
 //		notify_notification_clear_actions(n);
 
-		n = notify_notification_new (node_get_title(node_p), labelText_now_p, NULL, NULL);
+		n = notify_notification_new (node_get_title(node_p), labelText_now_p, NULL);
 
 		notify_notification_set_icon_from_pixbuf (n,node_get_icon(node_p));
 
@@ -223,7 +223,7 @@ notif_libnotify_node_has_new_items (node
 
 	labelSummary_p = g_strdup_printf (ngettext ("%s has %d new / updated headline\n", "%s has %d new / updated headlines\n", item_count), 
 	                                  node_get_title (node), item_count);
-	n = notify_notification_new ( _("Feed Update"), labelSummary_p, NULL, NULL);
+	n = notify_notification_new ( _("Feed Update"), labelSummary_p, NULL);
 	g_free(labelSummary_p);
 
 	notify_notification_set_icon_from_pixbuf (n, node_get_icon (node));
