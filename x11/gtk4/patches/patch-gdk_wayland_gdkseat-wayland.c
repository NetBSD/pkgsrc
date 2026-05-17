$NetBSD: patch-gdk_wayland_gdkseat-wayland.c,v 1.2 2026/05/17 15:49:05 wiz Exp $

Allow building on systems without evdev
https://github.com/torvalds/linux/blob/6916d5703ddf9a38f1f6c2cc793381a24ee914c6/include/uapi/linux/input-event-codes.h

--- gdk/wayland/gdkseat-wayland.c.orig	2026-04-29 22:39:35.000000000 +0000
+++ gdk/wayland/gdkseat-wayland.c
@@ -51,6 +51,16 @@
 #include <dev/evdev/input.h>
 #elif defined(HAVE_LINUX_INPUT_H)
 #include <linux/input.h>
+#else
+#ifndef BTN_LEFT
+#define BTN_LEFT       (0x110)
+#define BTN_RIGHT      (0x111)
+#define BTN_MIDDLE     (0x112)
+#define BTN_FORWARD    (0x115)
+#define BTN_BACK       (0x116)
+#define BTN_STYLUS     (0x14b)
+#define BTN_STYLUS2    (0x14c)
+#endif
 #endif
 
 #define WL_POINTER_HAS_FRAME 5
