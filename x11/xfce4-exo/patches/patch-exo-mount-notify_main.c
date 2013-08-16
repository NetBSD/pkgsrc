$NetBSD: patch-exo-mount-notify_main.c,v 1.1 2013/08/16 06:45:13 obache Exp $

* for libnotify-0.7 API change

--- exo-mount-notify/main.c.orig	2009-01-12 20:33:40.000000000 +0000
+++ exo-mount-notify/main.c
@@ -243,7 +243,7 @@ main (int argc, char **argv)
     }
 
   /* setup the notification */
-  notification = notify_notification_new (summary, message, opt_icon, NULL);
+  notification = notify_notification_new (summary, message, opt_icon);
   g_signal_connect (G_OBJECT (notification), "closed", G_CALLBACK (gtk_main_quit), NULL);
   g_object_add_weak_pointer (G_OBJECT (notification), (gpointer) &notification);
   notify_notification_set_urgency (notification, NOTIFY_URGENCY_CRITICAL);
