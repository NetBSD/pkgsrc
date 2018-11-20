$NetBSD: patch-gdk_quartz_gdkscreen-quartz.c,v 1.1 2018/11/20 08:13:56 maya Exp $
From 2a392c220d992ba21b1e250be2497248658cfcdb Mon Sep 17 00:00:00 2001
From: Ignacio Casal Quinteiro <qignacio@amazon.com>
Date: Sun, 7 Oct 2018 21:51:35 +0200
Subject: [PATCH] quartz: do not cache the screen in the gdkmonitor

Instead we just cache the monitor number and get
out of it the nsscreen when it is needed. This is
a requirement since it nsscreen it is not supposed
to be cached.

Fixes: https://gitlab.gnome.org/GNOME/gtk/issues/1312

--- gdk/quartz/gdkscreen-quartz.c.orig	2018-11-17 23:32:33.000000000 +0000
+++ gdk/quartz/gdkscreen-quartz.c
@@ -156,7 +156,7 @@ gdk_quartz_screen_calculate_layout (GdkQ
                                                 "display", display,
                                                 NULL);
       g_ptr_array_add (display_quartz->monitors, monitor);
-      monitor->nsscreen = [array objectAtIndex:i];
+      monitor->monitor_num = i;
 
       NSRect rect = [[array objectAtIndex:i] frame];
 
