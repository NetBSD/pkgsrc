$NetBSD: patch-src_locker.c,v 1.1 2013/06/15 12:25:23 khorben Exp $

API change in libDesktop 0.0.10

--- src/locker.c.orig	2012-10-12 23:18:24.000000000 +0000
+++ src/locker.c
@@ -268,8 +268,10 @@ Locker * locker_new(char const * demo, c
 			GDK_WINDOW_XID(root), ScreenSaverNotifyMask);
 	gdk_x11_register_standard_event_type(locker->display, locker->event, 1);
 	gdk_window_add_filter(root, _locker_on_filter, locker);
-	desktop_message_register(LOCKER_CLIENT_MESSAGE, _locker_on_message,
-			locker);
+	/* listen to desktop messages */
+	gtk_widget_realize(locker->windows[0]);
+	desktop_message_register(locker->windows[0], LOCKER_CLIENT_MESSAGE,
+			_locker_on_message, locker);
 	return locker;
 }
 
