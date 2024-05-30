$NetBSD: patch-glfw_wl__init.c,v 1.2 2024/05/30 15:00:54 ktnb Exp $

Support non-evdev platforms.

--- glfw/wl_init.c.orig	2024-05-25 03:37:36.000000000 +0000
+++ glfw/wl_init.c
@@ -44,6 +44,7 @@
 #include <sys/socket.h>
 #include <wayland-client.h>
 #include <stdio.h>
+#include <errno.h>
 // Needed for the BTN_* defines
 #ifdef __has_include
 #if __has_include(<linux/input.h>)
@@ -51,9 +52,13 @@
 #elif __has_include(<dev/evdev/input.h>)
 #include <dev/evdev/input.h>
 #endif
-#else
-#include <linux/input.h>
 #endif
+#ifndef BTN_LEFT
+#define BTN_LEFT	(0x110)
+#define BTN_RIGHT	(0x111)
+#define BTN_MIDDLE	(0x112)
+#endif
+
 
 #define debug debug_rendering
 
