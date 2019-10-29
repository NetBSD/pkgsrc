$NetBSD: patch-gdk_wayland_gdkdevice-wayland.c,v 1.2 2019/10/29 22:46:39 nia Exp $

Allow building on systems without evdev.

--- gdk/wayland/gdkdevice-wayland.c.orig	2019-04-10 19:30:43.000000000 +0000
+++ gdk/wayland/gdkdevice-wayland.c
@@ -44,6 +44,14 @@
 #include <dev/evdev/input.h>
 #elif defined(HAVE_LINUX_INPUT_H)
 #include <linux/input.h>
+#else
+#ifndef BTN_LEFT
+#define BTN_LEFT	(0x110)
+#define BTN_RIGHT	(0x111)
+#define BTN_MIDDLE	(0x112)
+#define BTN_STYLUS	(0x14b)
+#define BTN_STYLUS2	(0x14c)
+#endif
 #endif
 
 #define BUTTON_BASE (BTN_LEFT - 1) /* Used to translate to 1-indexed buttons */
