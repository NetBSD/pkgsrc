$NetBSD: patch-xfce4-settings-helper_accessibility.c,v 1.1 2013/08/16 07:42:55 obache Exp $

* for libnotify-0.7 API change

--- xfce4-settings-helper/accessibility.c.orig	2010-05-21 17:05:32.000000000 +0000
+++ xfce4-settings-helper/accessibility.c
@@ -417,7 +417,7 @@ xfce_accessibility_helper_notification_s
     if (helper->notification == NULL)
     {
         /* create a new notification */
-        helper->notification = notify_notification_new (summary, body, "keyboard", NULL);
+        helper->notification = notify_notification_new (summary, body, "keyboard");
 
         /* close signal */
         g_signal_connect (G_OBJECT (helper->notification), "closed", G_CALLBACK (xfce_accessibility_helper_notification_closed), helper);
