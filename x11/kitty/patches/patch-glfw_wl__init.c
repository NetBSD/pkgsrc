$NetBSD: patch-glfw_wl__init.c,v 1.3 2024/09/30 17:51:45 ktnb Exp $

Support non-evdev platforms.

--- glfw/wl_init.c.orig	2024-09-25 04:04:28.000000000 +0000
+++ glfw/wl_init.c
@@ -53,8 +53,11 @@
 #elif __has_include(<dev/evdev/input.h>)
 #include <dev/evdev/input.h>
 #endif
-#else
-#include <linux/input.h>
+#endif
+#ifndef BTN_LEFT
+#define BTN_LEFT	(0x110)
+#define BTN_RIGHT	(0x111)
+#define BTN_MIDDLE	(0x112)
 #endif
 
 #define debug debug_rendering
