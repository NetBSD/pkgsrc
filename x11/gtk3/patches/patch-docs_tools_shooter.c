$NetBSD: patch-docs_tools_shooter.c,v 1.1 2019/01/01 19:57:58 leot Exp $

Fix a typo.

--- docs/tools/shooter.c.orig	2018-12-12 17:46:09.000000000 +0000
+++ docs/tools/shooter.c
@@ -170,7 +170,7 @@ take_window_shot (Window         child,
       y_orig = 0;
     }
 
-  if (x_orig + width > gdk_screen_get_width (gdk_screen_get_dfeault ()))
+  if (x_orig + width > gdk_screen_get_width (gdk_screen_get_default ()))
     width = gdk_screen_width () - x_orig;
 
   if (y_orig + height > gdk_screen_get_height (gdk_screen_get_default ()))
