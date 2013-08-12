$NetBSD: patch-src_gs-lock-plug.c,v 1.1 2013/08/12 12:28:19 obache Exp $

* libnotify>=0.7 API change

--- src/gs-lock-plug.c.orig	2010-09-28 20:36:51.000000000 +0000
+++ src/gs-lock-plug.c
@@ -1090,7 +1090,7 @@ submit_note (GtkButton  *button,
         strftime (summary, 128, "%X", tmp);
 
         notify_init ("gnome-screensaver-dialog");
-        note = notify_notification_new (summary, escaped_text, NULL, NULL);
+        note = notify_notification_new (summary, escaped_text, NULL);
         notify_notification_set_timeout (note, NOTIFY_EXPIRES_NEVER);
         notify_notification_show (note, NULL);
         g_object_unref (note);
