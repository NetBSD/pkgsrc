$NetBSD: patch-libswc_seat-ws.c,v 1.1 2024/05/19 16:01:26 nia Exp $

Update for latest version of pointer API.

https://github.com/michaelforney/swc/pull/76

--- libswc/seat-ws.c.orig	2024-05-19 15:46:59.732010088 +0000
+++ libswc/seat-ws.c
@@ -274,11 +274,15 @@ handle_ws_data(int fd, uint32_t mask, vo
 			break;
 		case WSCONS_EVENT_MOUSE_DELTA_Z:
 			pos = wl_fixed_from_int(ev.value * 10);
-			pointer_handle_axis(seat->base.pointer, time, 0, pos);
+			pointer_handle_axis(seat->base.pointer, time,
+				WL_POINTER_AXIS_VERTICAL_SCROLL,
+				WL_POINTER_AXIS_SOURCE_WHEEL, pos, pos * 12);
 			break;
 		case WSCONS_EVENT_MOUSE_DELTA_W:
 			pos = wl_fixed_from_int(ev.value * 10);
-			pointer_handle_axis(seat->base.pointer, time, 1, pos);
+			pointer_handle_axis(seat->base.pointer, time,
+				WL_POINTER_AXIS_HORIZONTAL_SCROLL,
+				WL_POINTER_AXIS_SOURCE_WHEEL, pos, pos * 12);
 			break;
 		case WSCONS_EVENT_MOUSE_ABSOLUTE_X:
 			pos = wl_fixed_from_int(ev.value);
