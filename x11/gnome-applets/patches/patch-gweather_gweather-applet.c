$NetBSD: patch-gweather_gweather-applet.c,v 1.1 2013/08/14 05:59:16 obache Exp $

* moved to libnotify version 0.7
  https://git.gnome.org/browse/gnome-applets/commit/?id=f6b5bf454a61ca0090a1a32b798045a807d8ddad

--- gweather/gweather-applet.c.orig	2010-11-22 14:39:36.000000000 +0000
+++ gweather/gweather-applet.c
@@ -471,8 +471,7 @@ update_finish (WeatherInfo *info, gpoint
 			 if (icon == NULL)
 				 icon = "stock-unknown";
 	           	 
-			 n = notify_notification_new (message, detail, icon,
-					 gw_applet->container);
+			 n = notify_notification_new (message, detail, icon);
 	
 		   	 notify_notification_show (n, &error);
 			 if (error)
