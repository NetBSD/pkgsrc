$NetBSD: patch-gdk_x11_gdkscreen-x11.c,v 1.1 2017/11/06 10:00:57 tnn Exp $

From 74720117c9f12b01099ab55043d80c9fa21f44a5 Mon Sep 17 00:00:00 2001
From: Matthias Clasen <mclasen@redhat.com>
Date: Sat, 28 Oct 2017 10:22:30 -0400
Subject: Revert "gdkscreen-x11: Enable RandR on VirtualBox"

This reverts commit f2ba6ca47322a17b37fb92662fc9552b4f106f10.

This change was causing problems with several X servers,
see https://bugzilla.gnome.org/show_bug.cgi?id=780101

--- gdk/x11/gdkscreen-x11.c.orig	2017-10-02 16:00:49.000000000 +0000
+++ gdk/x11/gdkscreen-x11.c
@@ -408,6 +408,7 @@ init_randr15 (GdkScreen *screen, gboolea
   RROutput primary_output = None;
   RROutput first_output = None;
   int i;
+  gboolean randr12_compat = FALSE;
   XRRMonitorInfo *rr_monitors;
   int num_rr_monitors;
   int old_primary;
@@ -452,6 +453,9 @@ init_randr15 (GdkScreen *screen, gboolea
       if (output_info == NULL)
         continue;
 
+      /* Non RandR1.2+ X driver have output name "default" */
+      randr12_compat |= !g_strcmp0 (output_info->name, "default");
+
       if (output_info->connection == RR_Disconnected)
         {
           XRRFreeOutputInfo (output_info);
@@ -531,6 +535,19 @@ init_randr15 (GdkScreen *screen, gboolea
   XRRFreeMonitors (rr_monitors);
   XRRFreeScreenResources (resources);
 
+  /* non RandR 1.2+ X driver doesn't return any usable multihead data */
+  if (randr12_compat)
+    {
+      for (i = 0; i < x11_display->monitors->len; i++)
+        {
+          GdkX11Monitor *monitor = x11_display->monitors->pdata[i];
+          if (monitor->remove)
+            gdk_display_monitor_removed (display, GDK_MONITOR (monitor));
+        }
+      g_ptr_array_remove_range (x11_display->monitors, 0, x11_display->monitors->len);
+      return FALSE;
+    }
+
   for (i = x11_display->monitors->len - 1; i >= 0; i--)
     {
       GdkX11Monitor *monitor = x11_display->monitors->pdata[i];
@@ -593,6 +610,7 @@ init_randr13 (GdkScreen *screen, gboolea
   RROutput primary_output = None;
   RROutput first_output = None;
   int i;
+  gboolean randr12_compat = FALSE;
   int old_primary;
 
   if (!x11_display->have_randr13)
@@ -616,6 +634,9 @@ init_randr13 (GdkScreen *screen, gboolea
       XRROutputInfo *output_info =
         XRRGetOutputInfo (x11_screen->xdisplay, resources, output);
 
+      /* Non RandR1.2+ X driver have output name "default" */
+      randr12_compat |= !g_strcmp0 (output_info->name, "default");
+
       if (output_info->connection == RR_Disconnected)
         {
           XRRFreeOutputInfo (output_info);
@@ -696,7 +717,17 @@ init_randr13 (GdkScreen *screen, gboolea
 
   XRRFreeScreenResources (resources);
 
-  /* Which usable multihead data is not returned in non RandR 1.2+ X driver? */
+  if (randr12_compat)
+    {
+      for (i = 0; i < x11_display->monitors->len; i++)
+        {
+          GdkX11Monitor *monitor = x11_display->monitors->pdata[i];
+          if (monitor->remove)
+            gdk_display_monitor_removed (display, GDK_MONITOR (monitor));
+        }
+      g_ptr_array_remove_range (x11_display->monitors, 0, x11_display->monitors->len);
+      return FALSE;
+    }
 
   for (i = x11_display->monitors->len - 1; i >= 0; i--)
     {
