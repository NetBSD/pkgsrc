$NetBSD: patch-src_x11_x.c,v 1.1 2023/01/09 18:44:17 vins Exp $

Allow building on systems without evdev.

--- src/x11/x.c.orig	2022-06-27 12:43:39.000000000 +0000
+++ src/x11/x.c
@@ -19,7 +19,14 @@
 #include <X11/Xlib.h>
 #include <X11/Xresource.h>
 #include <X11/Xutil.h>
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <linux/input-event-codes.h>
+#else
+#define BTN_LEFT    (0x110)
+#define BTN_RIGHT   (0x111)
+#define BTN_MIDDLE  (0x112)
+#define BTN_TOUCH   (0x14a)
+#endif
 
 #include "../dbus.h"
 #include "../draw.h"
