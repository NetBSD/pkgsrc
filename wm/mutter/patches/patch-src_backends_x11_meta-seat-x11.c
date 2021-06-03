$NetBSD: patch-src_backends_x11_meta-seat-x11.c,v 1.1 2021/06/03 15:04:57 cirnatdan Exp $

Hide Linux-specific evdev code under #ifdefs

--- src/backends/x11/meta-seat-x11.c.orig	2021-03-20 12:08:54.069907200 +0000
+++ src/backends/x11/meta-seat-x11.c
@@ -17,8 +17,9 @@
  * Author: Carlos Garnacho <carlosg@gnome.org>
  */
 #include "config.h"
-
+#ifdef __linux__
 #include <linux/input-event-codes.h>
+#endif
 #include <X11/extensions/XInput2.h>
 #include <X11/extensions/XKB.h>
 
@@ -1731,7 +1732,7 @@ get_source_device_checked (MetaSeatX11  
 
   return source_device;
 }
-
+#ifdef __linux__
 static uint32_t
 evdev_button_code (uint32_t x_button)
 {
@@ -1752,7 +1753,6 @@ evdev_button_code (uint32_t x_button)
     case 3:
       button = BTN_RIGHT;
       break;
-
     default:
       button = x_button + (BTN_LEFT - 1) + 4;
       break;
@@ -1760,7 +1760,7 @@ evdev_button_code (uint32_t x_button)
 
   return button;
 }
-
+#endif
 gboolean
 meta_seat_x11_translate_event (MetaSeatX11  *seat,
                                XEvent       *xevent,
@@ -2048,7 +2048,9 @@ meta_seat_x11_translate_event (MetaSeatX
             event->button.time = xev->time;
             translate_coords (stage_x11, xev->event_x, xev->event_y, &event->button.x, &event->button.y);
             event->button.button = xev->detail;
+#ifdef __linux__
             event->button.evdev_code = evdev_button_code (xev->detail);
+#endif
             meta_input_device_x11_translate_state (event,
                                                    &xev->mods,
                                                    &xev->buttons,
