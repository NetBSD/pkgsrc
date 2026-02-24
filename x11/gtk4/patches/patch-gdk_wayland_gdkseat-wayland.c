$NetBSD: patch-gdk_wayland_gdkseat-wayland.c,v 1.1 2026/02/24 18:05:00 kikadf Exp $

Allow building on systems without evdev

--- gdk/wayland/gdkseat-wayland.c.orig	2025-11-20 05:08:31.000000000 +0000
+++ gdk/wayland/gdkseat-wayland.c
@@ -51,6 +51,14 @@
 #include <dev/evdev/input.h>
 #elif defined(HAVE_LINUX_INPUT_H)
 #include <linux/input.h>
+#else
+#ifndef BTN_LEFT
+#define BTN_LEFT       (0x110)
+#define BTN_RIGHT      (0x111)
+#define BTN_MIDDLE     (0x112)
+#define BTN_STYLUS     (0x14b)
+#define BTN_STYLUS2    (0x14c)
+#endif
 #endif
 
 #define WL_POINTER_HAS_FRAME 5
