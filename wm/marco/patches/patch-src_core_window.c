$NetBSD: patch-src_core_window.c,v 1.1 2020/11/21 03:48:07 gutteridge Exp $

window: do not unfocus on new window. Fix keyboard input on fullscreen VLC.
https://github.com/mate-desktop/marco/commit/6ea23df6aa8a42973a1bb42c5c618b322d47488e

--- src/core/window.c.orig	2020-08-04 18:35:42.000000000 +0000
+++ src/core/window.c
@@ -2175,23 +2175,7 @@ meta_window_show (MetaWindow *window)
       ( (!place_on_top_on_map && !takes_focus_on_map) ||
       will_be_covered )
     ) {
-      if (meta_window_is_ancestor_of_transient (focus_window, window))
-        {
-          /* This happens for error dialogs or alerts; these need to remain on
-           * top, but it would be confusing to have its ancestor remain
-           * focused.
-           */
-          meta_topic (META_DEBUG_STARTUP,
-                      "The focus window %s is an ancestor of the newly mapped "
-                      "window %s which isn't being focused.  Unfocusing the "
-                      "ancestor.\n",
-                      focus_window->desc, window->desc);
-
-          meta_display_focus_the_no_focus_window (window->display,
-                                                  window->screen,
-                                                  timestamp);
-        }
-      else
+      if (!meta_window_is_ancestor_of_transient (focus_window, window))
         {
           needs_stacking_adjustment = TRUE;
           if (!window->placed)
