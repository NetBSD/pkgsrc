$NetBSD: patch-driver_screens.c,v 1.1 2021/06/05 08:50:31 wiz Exp $

https://github.com/QubesOS/qubes-xscreensaver/blob/master/0001-Fix-updating-outputs-info.patch

From c1e43f7fa01b7536bc90ad5a9b61c568f4db4dd1 Mon Sep 17 00:00:00 2001
From: Marek Marczykowski-Górecki <marmarek@invisiblethingslab.com>
Date: Tue, 18 May 2021 15:41:55 +0200
Subject: [PATCH] Fix updating outputs info

When an output is disconnected, update_screen_layout() will try to unset
a property on window assigned to that output. It does that by iterating
si->screens up to 'count', while 'good_count' signifies how many outputs
are currently connected (good_count <= count). si->screens has few more
entries allocated (at start 10), but if there are more disconnected
outputs, the iteration will go beyond si->screens array.
The only out of bound access there is reading window ID to delete
property from, which in most cases will be a bogus number -> crashing
xscreensaver with BadWindow error.

Fix this by allocating array up to full 'count' entries, even if much
fewer outputs are connected at the moment.


--- driver/screens.c.orig	2020-07-29 22:32:11.000000000 +0000
+++ driver/screens.c
@@ -1020,9 +1020,9 @@ update_screen_layout (saver_info *si)
         calloc (sizeof(*si->screens), si->ssi_count);
     }
 
-  if (si->ssi_count <= good_count)
+  if (si->ssi_count <= count)
     {
-      si->ssi_count = good_count + 10;
+      si->ssi_count = count;
       si->screens = (saver_screen_info *)
         realloc (si->screens, sizeof(*si->screens) * si->ssi_count);
       memset (si->screens + si->nscreens, 0, 
