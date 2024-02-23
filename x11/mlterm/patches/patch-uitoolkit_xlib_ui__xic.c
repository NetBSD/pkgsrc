$NetBSD: patch-uitoolkit_xlib_ui__xic.c,v 1.1 2024/02/23 12:44:29 tsutsui Exp $

- pull an XIM fix commit to avoid possible stall with ibus-mozc
 https://github.com/arakiken/mlterm/commit/b8750c1

--- uitoolkit/xlib/ui_xic.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/xlib/ui_xic.c
@@ -201,6 +201,7 @@ static int create_xic(ui_window_t *win) 
   win->xic->ic = xic;
   win->xic->fontset = fontset;
   win->xic->style = selected_style;
+  win->xic->spot = spot;
 
   xim_ev_mask = 0;
 
@@ -352,6 +353,10 @@ int ui_xic_resized(ui_window_t *win) {
     spot.y = 0;
   }
 
+  if (spot.x == win->xic->spot.x && spot.y == win->xic->spot.y) {
+    return 0;
+  }
+
   if ((preedit_attr = XVaCreateNestedList(0,
 #ifdef SET_XNAREA_ATTR
                                           XNArea, &rect,
@@ -365,6 +370,7 @@ int ui_xic_resized(ui_window_t *win) {
   }
 
   XSetICValues(win->xic->ic, XNPreeditAttributes, preedit_attr, NULL);
+  win->xic->spot = spot;
 
   XFree(preedit_attr);
 
@@ -385,6 +391,10 @@ int ui_xic_set_spot(ui_window_t *win) {
     return 0;
   }
 
+  if (spot.x == win->xic->spot.x && spot.y == win->xic->spot.y) {
+    return 0;
+  }
+
   if ((preedit_attr = XVaCreateNestedList(0, XNSpotLocation, &spot, NULL)) == NULL) {
 #ifdef DEBUG
     bl_warn_printf(BL_DEBUG_TAG " XvaCreateNestedList failed.\n");
@@ -394,6 +404,7 @@ int ui_xic_set_spot(ui_window_t *win) {
   }
 
   XSetICValues(win->xic->ic, XNPreeditAttributes, preedit_attr, NULL);
+  win->xic->spot = spot;
 
   XFree(preedit_attr);
 
