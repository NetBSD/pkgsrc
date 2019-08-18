$NetBSD: patch-gdk_wayland_gdkdevice-wayland.c,v 1.1 2019/08/18 16:47:38 nia Exp $

Allow building on systems without evdev.

--- gdk/wayland/gdkdevice-wayland.c.orig	2019-04-10 19:30:43.000000000 +0000
+++ gdk/wayland/gdkdevice-wayland.c
@@ -44,6 +44,14 @@
 #include <dev/evdev/input.h>
 #elif defined(HAVE_LINUX_INPUT_H)
 #include <linux/input.h>
+#else
+#ifndef BTN_LEFT
+#define BTN_LEFT	(0)
+#define BTN_MIDDLE	(1)
+#define BTN_RIGHT	(2)
+#define BTN_STYLUS	(98)
+#define BTN_STYLUS2	(99)
+#endif
 #endif
 
 #define BUTTON_BASE (BTN_LEFT - 1) /* Used to translate to 1-indexed buttons */
