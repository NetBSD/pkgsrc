$NetBSD: patch-common_xfdesktop-common.c,v 1.1 2025/04/27 21:44:56 gutteridge Exp $

Default the monitor name to "default" if we cannot get anything more
specific from gdk_monitor_get_model().

Reported in https://gitlab.xfce.org/xfce/xfdesktop/-/issues/380

--- common/xfdesktop-common.c.orig	2024-11-03 07:01:56.000000000 +0100
+++ common/xfdesktop-common.c
@@ -114,12 +114,16 @@ xfdesktop_get_monitor_name_from_gtk_widg
     GdkWindow     *window = NULL;
     GdkDisplay    *display = NULL;
     GdkMonitor    *monitor = NULL;
+    const gchar   *monitor_name = NULL;
 
     window = gtk_widget_get_window(widget);
     display = gdk_window_get_display(window);
     monitor = gdk_display_get_monitor(display, monitor_num);
 
-    return g_strdup(gdk_monitor_get_model(monitor));
+    monitor_name = gdk_monitor_get_model(monitor);
+    if (monitor_name == NULL)
+        monitor_name = "default";
+    return g_strdup(monitor_name);
 }
 
 gint
