$NetBSD: patch-src_window.c,v 1.1 2013/05/22 18:01:25 tron Exp $

Fix build with WindowMaker 0.95.4.

--- src/window.c.orig	2004-07-22 04:09:55.000000000 +0100
+++ src/window.c	2013-05-22 18:50:59.000000000 +0100
@@ -1069,7 +1069,7 @@
 	 WMReleasePropList (all_keys);
       }
 
-      if (WMWritePropListToFile (newwm, orig_wmaker_fname, YES))
+      if (WMWritePropListToFile (newwm, orig_wmaker_fname))
       {
 	 changed = NO;
 	 message (_("Window Maker config file '%s' saved."),
