$NetBSD: patch-gdk_quartz_gdkmonitor-quartz.c,v 1.1 2018/11/20 08:13:56 maya Exp $
From 2a392c220d992ba21b1e250be2497248658cfcdb Mon Sep 17 00:00:00 2001
From: Ignacio Casal Quinteiro <qignacio@amazon.com>
Date: Sun, 7 Oct 2018 21:51:35 +0200
Subject: [PATCH] quartz: do not cache the screen in the gdkmonitor

Instead we just cache the monitor number and get
out of it the nsscreen when it is needed. This is
a requirement since it nsscreen it is not supposed
to be cached.

Fixes: https://gitlab.gnome.org/GNOME/gtk/issues/1312

--- gdk/quartz/gdkmonitor-quartz.c.orig	2018-11-17 23:32:33.000000000 +0000
+++ gdk/quartz/gdkmonitor-quartz.c
@@ -35,12 +35,19 @@ gdk_quartz_monitor_get_workarea (GdkMoni
 
   GDK_QUARTZ_ALLOC_POOL;
 
-  NSRect rect = [quartz_monitor->nsscreen visibleFrame];
-
-  dest->x = rect.origin.x - quartz_screen->min_x;
-  dest->y = quartz_screen->height - (rect.origin.y + rect.size.height) + quartz_screen->min_y;
-  dest->width = rect.size.width;
-  dest->height = rect.size.height;
+  NSArray *array = [NSScreen screens];
+  if (quartz_monitor->monitor_num < [array count])
+    {
+      NSScreen *screen = [array objectAtIndex:quartz_monitor->monitor_num];
+      NSRect rect = [screen visibleFrame];
+
+      dest->x = rect.origin.x - quartz_screen->min_x;
+      dest->y = quartz_screen->height - (rect.origin.y + rect.size.height) + quartz_screen->min_y;
+      dest->width = rect.size.width;
+      dest->height = rect.size.height;
+    }
+  else
+    *dest = monitor->geometry;
 
   GDK_QUARTZ_RELEASE_POOL;
 }
