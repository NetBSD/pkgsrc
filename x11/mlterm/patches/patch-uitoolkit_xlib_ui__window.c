$NetBSD: patch-uitoolkit_xlib_ui__window.c,v 1.1 2019/02/17 16:57:59 tsutsui Exp $

- pull upstream fix:
 http://sourceforge.net/projects/mlterm/files/01release/mlterm-3.8.7/mlterm-3.8.7-fixes.patch/download
 https://bitbucket.org/arakiken/mlterm/commits/f41d3a433fcfc573fe7d09fb67a54cfae7d247c5

--- uitoolkit/xlib/ui_window.c.orig	2018-10-27 14:29:17.000000000 +0000
+++ uitoolkit/xlib/ui_window.c
@@ -1337,9 +1337,11 @@ int ui_window_show(ui_window_t *win, int
     size_hints.height_inc = total_height_inc(win);
     size_hints.min_width = total_min_width(win);
     size_hints.min_height = total_min_height(win);
-    size_hints.base_width = size_hints.min_width > size_hints.width_inc ?
+    size_hints.base_width = (size_hints.width_inc > 0 &&
+                             size_hints.min_width > size_hints.width_inc) ?
                             size_hints.min_width % size_hints.width_inc : 0;
-    size_hints.base_height = size_hints.min_height > size_hints.height_inc ?
+    size_hints.base_height = (size_hints.height_inc > 0 &&
+                              size_hints.min_height > size_hints.height_inc) ?
                              size_hints.min_height % size_hints.height_inc : 0;
 
 #ifdef DEBUG
@@ -1586,9 +1588,11 @@ void ui_window_set_normal_hints(ui_windo
   size_hints.height_inc = total_height_inc(root);
   size_hints.min_width = total_min_width(root);
   size_hints.min_height = total_min_height(root);
-  size_hints.base_width =
-      size_hints.min_width > size_hints.width_inc ? size_hints.min_width % size_hints.width_inc : 0;
-  size_hints.base_height = size_hints.min_height > size_hints.height_inc ?
+  size_hints.base_width = (size_hints.width_inc > 0 &&
+                           size_hints.min_width > size_hints.width_inc) ?
+                          size_hints.min_width % size_hints.width_inc : 0;
+  size_hints.base_height = (size_hints.height_inc > 0 &&
+                            size_hints.min_height > size_hints.height_inc) ?
                            size_hints.min_height % size_hints.height_inc : 0;
   size_hints.flags = PMinSize | PResizeInc | PBaseSize;
 
