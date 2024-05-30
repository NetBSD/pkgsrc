$NetBSD: patch-glfw_wl__client__side__decorations.c,v 1.1 2024/05/30 15:00:54 ktnb Exp $

Support non-evdev platforms.

--- glfw/wl_client_side_decorations.c.orig	2024-05-25 03:37:36.000000000 +0000
+++ glfw/wl_client_side_decorations.c
@@ -12,6 +12,11 @@
 #include <errno.h>
 #include <string.h>
 #include <stdlib.h>
+#ifndef BTN_LEFT
+#define BTN_LEFT	(0x110)
+#define BTN_RIGHT	(0x111)
+#define BTN_MIDDLE	(0x112)
+#endif
 
 #define decs window->wl.decorations
 #define debug debug_rendering
