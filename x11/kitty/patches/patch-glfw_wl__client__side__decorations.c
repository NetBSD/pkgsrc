$NetBSD: patch-glfw_wl__client__side__decorations.c,v 1.2 2026/07/19 00:35:25 ktnb Exp $

Support non-evdev platforms.

--- glfw/wl_client_side_decorations.c.orig	2026-07-18 02:07:54.000000000 +0000
+++ glfw/wl_client_side_decorations.c
@@ -22,6 +22,11 @@
 #else
 #include <linux/input.h>
 #endif
+#ifndef BTN_LEFT
+#define BTN_LEFT	(0x110)
+#define BTN_RIGHT	(0x111)
+#define BTN_MIDDLE	(0x112)
+#endif
 
 #define decs window->wl.decorations
 #define debug debug_rendering
