$NetBSD: patch-src_afterstep_housekeeping.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/afterstep/housekeeping.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/afterstep/housekeeping.c
@@ -245,7 +245,7 @@ void PasteSelection (ScreenInfo * scr)
 						ch = '\r';
 					event.xkey.keycode = XKeysymToKeycode (dpy, ch + '@');
 					event.xkey.state |= ControlMask;
-				} else if (isupper (*buf)) {
+				} else if (isupper ((unsigned char)*buf)) {
 					event.xkey.keycode = XKeysymToKeycode (dpy, *buf);
 					event.xkey.state |= ShiftMask;
 				} else
