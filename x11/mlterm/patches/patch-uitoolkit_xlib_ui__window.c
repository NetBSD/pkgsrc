$NetBSD: patch-uitoolkit_xlib_ui__window.c,v 1.3 2026/05/04 19:51:32 tsutsui Exp $

- pull upstream change to fix "Typed keys are lost after keyboard
  focus change unntil pointer enters the mlterm window" problem
   https://github.com/arakiken/mlterm/issues/159
   https://github.com/arakiken/mlterm/commit/a8fae665

--- uitoolkit/xlib/ui_window.c.orig	2025-03-29 23:13:10.000000000 +0000
+++ uitoolkit/xlib/ui_window.c
@@ -226,7 +226,8 @@ static int update_transparent_picture(ui
      * (see xlib/ui_imagelib.c), return 1 not to set ParentRelative in
      * set_transparent().
      */
-    int x, y, pix_x, pix_y, width, height;
+    int x, y, pix_x, pix_y;
+    u_int width, height;
 
     if (!ui_window_get_visible_geometry(win, &x, &y, &pix_x, &pix_y, &width, &height)) {
       return 1;
@@ -475,9 +476,11 @@ static int is_descendant_window(ui_windo
   return 0;
 }
 
+#ifndef AVOID_CALL_XFILTEREVENT_TWICE
 static int is_in_the_same_window_family(ui_window_t *win, Window window) {
   return is_descendant_window(ui_get_root_window(win), window);
 }
+#endif
 
 static u_int total_min_width(ui_window_t *win) {
   u_int count;
@@ -1901,18 +1904,16 @@ int ui_window_receive_event(ui_window_t 
   }
 
   if (win->my_window != event->xany.window) {
+#ifndef AVOID_CALL_XFILTEREVENT_TWICE
     /*
      * XXX
-     * if some window invokes xim window open event and it doesn't have any xic
-     * ,
+     * if some window invokes xim window open event and it doesn't have any xic,
      * no xim window will be opened at XFilterEvent() in
      * ui_display_receive_next_event().
-     * but it is desired to open xim window of ui_screen when its event is
-     * invoked
-     * on scrollbar or title bar.
-     * this hack enables it , but this way won't deal with the case that
-     * multiple
-     * xics exist.
+     * Bbut it is desired to open xim window of ui_screen when its event is
+     * invoked on scrollbar or title bar.
+     * This hack enables it, but this way won't deal with the case that
+     * multiple xics exist.
      */
     if (win->xic) {
       if (is_in_the_same_window_family(win, event->xany.window) &&
@@ -1920,6 +1921,7 @@ int ui_window_receive_event(ui_window_t 
         return 1;
       }
     }
+#endif
 
     if (event->type == PropertyNotify && win == ui_get_root_window(win) &&
         (event->xproperty.atom == XA_XSETROOT_ID(win->disp->display) ||
