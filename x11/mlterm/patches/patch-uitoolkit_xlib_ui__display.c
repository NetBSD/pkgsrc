$NetBSD: patch-uitoolkit_xlib_ui__display.c,v 1.1 2026/05/04 19:51:32 tsutsui Exp $

- pull upstream change to fix "Typed keys are lost after keyboard
  focus change unntil pointer enters the mlterm window" problem
   https://github.com/arakiken/mlterm/issues/159
   https://github.com/arakiken/mlterm/commit/a8fae665

--- uitoolkit/xlib/ui_display.c.orig	2025-03-29 23:13:10.000000000 +0000
+++ uitoolkit/xlib/ui_display.c
@@ -269,10 +269,27 @@ static void close_display(ui_display_t *
   free(disp);
 }
 
+#ifdef AVOID_CALL_XFILTEREVENT_TWICE
+static Window get_xic_window(ui_window_t **windows, u_int num_windows) {
+  u_int count;
+  Window wxic;
+
+  for (count = 0; count < num_windows; count++) {
+    if (windows[count]->xic) {
+      return windows[count]->my_window;
+    } else if ((wxic = get_xic_window(windows[count]->children, windows[count]->num_children))) {
+      return wxic;
+    }
+  }
+
+  return None;
+}
+#endif
+
 /* --- global functions --- */
 
 ui_display_t *ui_display_open(char *disp_name, u_int depth) {
-  int count;
+  u_int count;
   ui_display_t *disp;
   void *p;
 
@@ -424,7 +441,7 @@ int ui_display_remove_root(ui_display_t 
 }
 
 void ui_display_idling(ui_display_t *disp) {
-  int count;
+  u_int count;
 
   for (count = 0; count < disp->num_roots; count++) {
     ui_window_idling(disp->roots[count]);
@@ -433,13 +450,43 @@ void ui_display_idling(ui_display_t *dis
 
 int ui_display_receive_next_event(ui_display_t *disp) {
   XEvent event;
-  int count;
+  u_int count;
 
   do {
     XNextEvent(disp->display, &event);
 
+#ifdef AVOID_CALL_XFILTEREVENT_TWICE
+    if (event.type == KeyPress || event.type == KeyRelease) {
+      /*
+       * See ui_window_receive_event().
+       * Calling XFilterEvent twice causes unexpected behavior.
+       * (https://github.com/arakiken/mlterm/issues/159)
+       */
+      Window wxic;
+
+      for (count = 0; ; count++) {
+        if (count >= disp->num_roots) { goto normal; }
+        if (event.xany.window == disp->roots[count]->my_window) { break; }
+      }
+
+      if ((wxic = get_xic_window(disp->roots[count]->children, disp->roots[count]->num_children))) {
+#ifdef __DEBUG
+        bl_debug_printf("Replace event.xany.window to cheat XFilterEvent. (%p -> %p)\n",
+                        event.xany.window, wxic);
+#endif
+        event.xany.window = wxic;
+      }
+      if (!XFilterEvent(&event, None)) {
+        ui_window_receive_event(disp->roots[count], &event);
+      }
+      continue;
+    }
+
+normal:
+#endif
     if (!XFilterEvent(&event, None)) {
       for (count = 0; count < disp->num_roots; count++) {
+        /* Check all roots to check MappingNotify (see ui_window.c) */
         ui_window_receive_event(disp->roots[count], &event);
       }
     }
