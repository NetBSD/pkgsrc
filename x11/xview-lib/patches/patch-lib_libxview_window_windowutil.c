$NetBSD: patch-lib_libxview_window_windowutil.c,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/window/windowutil.c.orig	2012-11-14 16:17:51.000000000 +0000
+++ lib/libxview/window/windowutil.c
@@ -508,7 +508,7 @@ window_set_cache_rect(window, rect)
 	}
 }
 
-Xv_private
+Xv_private void
 window_set_parent(window, parent)
     Xv_Window       window, parent;
 {
@@ -767,7 +767,7 @@ window_adjust_rects(rect_obj_list, paren
 
 	adjust_rect_obj(num_elems, this_sw, rect_obj_list, parent_width, parent_height);
 	window_outer_to_innerrect(&(rect_obj_list[this_sw]),
-				  rect_obj_list[this_sw].new_rect);
+				  &rect_obj_list[this_sw].new_rect);
     }
 }
 
