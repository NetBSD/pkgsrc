$NetBSD: patch-gdk_wayland_gdkdevice-wayland.c,v 1.3 2026/05/14 17:42:34 ryoon Exp $

Allow building on systems without evdev.

--- gdk/wayland/gdkdevice-wayland.c.orig	2026-03-23 02:24:49.000000000 +0000
+++ gdk/wayland/gdkdevice-wayland.c
@@ -45,6 +45,16 @@
 #include <dev/evdev/input.h>
 #elif defined(HAVE_LINUX_INPUT_H)
 #include <linux/input.h>
+#else
+#ifndef BTN_LEFT
+#define BTN_LEFT	(0x110)
+#define BTN_RIGHT	(0x111)
+#define BTN_MIDDLE	(0x112)
+#define BTN_FORWARD	(0x115)
+#define BTN_BACK	(0x116)
+#define BTN_STYLUS	(0x14b)
+#define BTN_STYLUS2	(0x14c)
+#endif
 #endif
 
 #define BUTTON_BASE (BTN_LEFT - 1) /* Used to translate to 1-indexed buttons */
