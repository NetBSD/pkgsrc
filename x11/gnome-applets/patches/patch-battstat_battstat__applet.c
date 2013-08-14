$NetBSD: patch-battstat_battstat__applet.c,v 1.1 2013/08/14 05:59:16 obache Exp $

* moved to libnotify version 0.7
  https://git.gnome.org/browse/gnome-applets/commit/?id=f6b5bf454a61ca0090a1a32b798045a807d8ddad

--- battstat/battstat_applet.c.orig	2010-11-22 14:38:27.000000000 +0000
+++ battstat/battstat_applet.c
@@ -435,7 +435,7 @@ battery_full_notify (GtkWidget *applet)
 			GTK_ICON_LOOKUP_USE_BUILTIN,
 			NULL);
 	
-	NotifyNotification *n = notify_notification_new (_("Your battery is now fully recharged"), "", /* "battery" */ NULL, applet);
+	NotifyNotification *n = notify_notification_new (_("Your battery is now fully recharged"), "", /* "battery" */ NULL);
 
 	/* XXX: it would be nice to pass this as a named icon */
 	notify_notification_set_icon_from_pixbuf (n, icon);
