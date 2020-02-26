$NetBSD: patch-glfw_wl__init.c,v 1.1 2020/02/26 15:47:14 nia Exp $

Support non-evdev platforms.

--- glfw/wl_init.c.orig	2019-11-27 04:25:00.000000000 +0000
+++ glfw/wl_init.c
@@ -48,8 +48,11 @@
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
 
 
