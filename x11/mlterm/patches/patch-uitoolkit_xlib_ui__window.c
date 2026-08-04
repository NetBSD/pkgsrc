$NetBSD: patch-uitoolkit_xlib_ui__window.c,v 1.5 2026/08/04 15:42:49 tsutsui Exp $

- pull upstream fix:
 https://github.com/arakiken/mlterm/commit/246c169e684a08f03c66554f2c4c35c6adbe8231
 > * xlib/ui_window.c:
 >   - Skip XSizeHints, XClassHint and XWMHints for child windows.
 >     (Enbugged at 3.9.5 / 4eb3aa4)
 >   - Not FocusIn event but XA_TAKE_FOCUS message calls
 >     ensure_input_focus().

--- uitoolkit/xlib/ui_window.c.orig	2026-07-05 16:18:25.000000000 +0000
+++ uitoolkit/xlib/ui_window.c
@@ -460,6 +460,7 @@ static void notify_property_to_children(
   }
 }
 
+#ifndef AVOID_CALL_XFILTEREVENT_TWICE
 static int is_descendant_window(ui_window_t *win, Window window) {
   u_int count;
 
@@ -476,7 +477,6 @@ static int is_descendant_window(ui_windo
   return 0;
 }
 
-#ifndef AVOID_CALL_XFILTEREVENT_TWICE
 static int is_in_the_same_window_family(ui_window_t *win, Window window) {
   return is_descendant_window(ui_get_root_window(win), window);
 }
@@ -734,16 +734,14 @@ static void reset_input_focus(ui_window_
   }
 }
 
-static void ensure_input_focus(ui_window_t *win) {
-  u_int count;
-
+static void ensure_input_focus(ui_window_t *win, Time time) {
   if (win->inputtable > 0) {
-    if (!win->is_focused) {
-      XSetInputFocus(win->disp->display, win->my_window, RevertToParent, CurrentTime);
-    }
+    XSetInputFocus(win->disp->display, win->my_window, RevertToParent, time);
   } else {
+    u_int count;
+
     for (count = 0; count < win->num_children; count++) {
-      ensure_input_focus(win->children[count]);
+      ensure_input_focus(win->children[count], time);
     }
   }
 }
@@ -1345,8 +1343,15 @@ int ui_window_show(ui_window_t *win, int
                           ACTUAL_HEIGHT(win), 0, win->fg_color.pixel, win->bg_color.pixel);
 #endif
 
-  /* Don't use win->parent here in case mlterm works as libvte. */
-  if (PARENT_WINDOWID_IS_TOP(win) || !(hint & HINT_CHILD_WINDOW_ATTR)) {
+
+  /*
+   * Do not use PARENT_WINDOWID_IS_TOP() instead of win->parent == NULL because
+   * the following block should be executed if mlterm starts by
+   * 'tabbed -c mlterm --parent' where win->parent_window != win->disp->my_window.
+   * The following block is not executed in libvte compatible library by
+   * '!(hint & HINT_CHILD_WINDOW_ATTR)'.
+   */
+  if (win->parent == NULL && !(hint & HINT_CHILD_WINDOW_ATTR)) {
     /* Root window */
 
     XSizeHints size_hints;
@@ -1367,6 +1372,9 @@ int ui_window_show(ui_window_t *win, int
     /*
      * XXX
      * x/y/width/height are obsoleted. (see XSizeHints(3))
+     * Not change the initial values even if window is resized or moved.
+     *
+     * ui_window_set_normal_hints() removes PSize and PWinGravity.
      */
     size_hints.x = win->x;
     size_hints.y = win->y;
@@ -1385,9 +1393,11 @@ int ui_window_show(ui_window_t *win, int
                               size_hints.min_height - total : 0;
 
 #ifdef DEBUG
-    bl_debug_printf(BL_DEBUG_TAG " Size hints => w %d h %d wi %d hi %d mw %d mh %d bw %d bh %d\n",
-                    size_hints.width, size_hints.height, size_hints.width_inc,
-                    size_hints.height_inc, size_hints.min_width, size_hints.min_height,
+    bl_debug_printf(BL_DEBUG_TAG
+                    " Size hints => x %d y %d w %d h %d wi %d hi %d mw %d mh %d bw %d bh %d\n",
+                    size_hints.x, size_hints.y, size_hints.width, size_hints.height,
+                    size_hints.width_inc, size_hints.height_inc,
+                    size_hints.min_width, size_hints.min_height,
                     size_hints.base_width, size_hints.base_height);
 #endif
 
@@ -1639,6 +1649,7 @@ void ui_window_set_maximize_flag(ui_wind
   }
 }
 
+/* This removes PSize and PWinGravity. */
 void ui_window_set_normal_hints(ui_window_t *win, u_int min_width, u_int min_height,
                                 u_int width_inc, u_int height_inc) {
   XSizeHints size_hints;
@@ -1977,16 +1988,12 @@ int ui_window_receive_event(ui_window_t 
 
     urgent_bell(win, 0);
 
-    if (!win->parent && get_num_inputtables(win) > 1) {
-      ensure_input_focus(win);
-    } else {
-      /*
-       * Cygwin/X can send FocusIn/FocusOut events not to top windows
-       * but to child ones in changing window focus, so don't encircle
-       * notify_focus_{in|out}_to_children with if(!win->parent).
-       */
-      notify_focus_in_to_children(win);
-    }
+    /*
+     * Cygwin/X can send FocusIn/FocusOut events not to top windows
+     * but to child ones in changing window focus, so don't encircle
+     * notify_focus_{in|out}_to_children with if(!win->parent).
+     */
+    notify_focus_in_to_children(win);
   } else if (event->type == FocusOut) {
 #ifdef __DEBUG
     bl_debug_printf("FOCUS OUT %p (parent %p)\n", event->xany.window, win->parent);
@@ -2493,23 +2500,33 @@ int ui_window_receive_event(ui_window_t 
 
     XDeleteProperty(win->disp->display, event->xselection.requestor, event->xselection.property);
   } else if (event->type == ClientMessage) {
-    if (event->xclient.format == 32 &&
-        event->xclient.data.l[0] == XA_DELETE_WINDOW(win->disp->display)) {
+    if (event->xclient.format == 32) {
+      if (event->xclient.data.l[0] == XA_DELETE_WINDOW(win->disp->display)) {
 #ifdef DEBUG
-      bl_warn_printf(BL_DEBUG_TAG " DeleteWindow message is received. exiting...\n");
+        bl_debug_printf(BL_DEBUG_TAG " Window %p receives DeleteWindow message. exiting...\n",
+                        event->xclient.window);
 #endif
-      if (win->window_destroyed) {
-        (*win->window_destroyed)(win);
-      } else {
-        exit(0);
+        if (win->window_destroyed) {
+          (*win->window_destroyed)(win);
+        } else {
+          exit(0);
+        }
+      } else if (event->xclient.data.l[0] == XA_TAKE_FOCUS(win->disp->display)) {
+#ifdef DEBUG
+        bl_debug_printf(BL_DEBUG_TAG " Window %p receives TakeFocus message.\n",
+                        event->xclient.window);
+#endif
+        if (event->xclient.window == win->my_window && win->parent == NULL &&
+            get_num_inputtables(win) > 1) {
+          /*
+           * XXX
+           * Input focus is not correctly set unless CurrentTime in shifting
+           * windows by Alt-Tab in KDE Plasma5 6.7.1.
+           */
+          ensure_input_focus(win, CurrentTime /* event->xclient.data.l[1] */);
+        }
       }
     }
-#if 0
-    else if (event->xclient.format == 32 &&
-             event->xclient.data.l[0] == XA_TAKE_FOCUS(win->disp->display)) {
-      bl_warn_printf(BL_DEBUG_TAG " TakeFocus message is received.\n");
-    }
-#endif
   } else if (event->type == PropertyNotify) {
     if (event->xproperty.atom == XA_SELECTION_PROP(win->disp->display) &&
         event->xproperty.state == PropertyNewValue) {
