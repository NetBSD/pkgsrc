$NetBSD: patch-src_reminder.c,v 1.1 2013/08/16 08:14:31 obache Exp $

* for libnotify-0.7 API change
  http://git.xfce.org/apps/orage/commit/src/reminder.c?id=bfa601ba135f84163eded2bb2e060e21d9ca08ce

--- src/reminder.c.orig	2009-04-14 22:58:27.000000000 +0000
+++ src/reminder.c
@@ -61,6 +61,12 @@
 #define ORAGE_DEBUG 1
 */
 
+/* Compatibility macro for < libnotify-0.7 */
+/* NOTIFY_CHECK_VERSION was created in 0.5.2 */
+#ifndef NOTIFY_CHECK_VERSION
+#deifne NOTIFY_CHECK_VERSION(x,y,z) 0
+#endif
+
 static void create_notify_reminder(alarm_struct *alarm);
 static void create_reminders(alarm_struct *alarm);
 static void reset_orage_alarm_clock();
@@ -425,8 +431,13 @@ static void create_notify_reminder(alarm
     strncpy(heading,  _("Reminder "), 199);
     if (alarm->title)
         g_strlcat(heading, alarm->title, 50);
+    /* since version 0.7.0, libnotify does not have the widget parameter in
+       notify_notification_new and it does not have function
+       notify_notification_attach_to_status_icon at all */
+#if NOTIFY_CHECK_VERSION(0, 7, 0)
+    n = notify_notification_new(heading, alarm->description, NULL);
+#else
     n = notify_notification_new(heading, alarm->description, NULL, NULL);
-    alarm->active_alarm->active_notify = n;
 #if GTK_CHECK_VERSION(2,10,0)
     if (g_par.trayIcon 
     && gtk_status_icon_is_embedded((GtkStatusIcon *)g_par.trayIcon))
@@ -438,6 +449,8 @@ static void create_notify_reminder(alarm
         notify_notification_attach_to_widget(n
                 , ((XfceTrayIcon *)g_par.trayIcon)->image);
 #endif
+#endif
+    alarm->active_alarm->active_notify = n;
 
     if (alarm->notify_timeout == -1)
         notify_notification_set_timeout(n, NOTIFY_EXPIRES_NEVER);
