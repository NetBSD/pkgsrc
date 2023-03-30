$NetBSD: patch-hw_xwayland_xwayland-input.c,v 1.1 2023/03/30 08:45:06 wiz Exp $

Linux-specific input code. Compiles, but probably won't work on non-Linux.

--- hw/xwayland/xwayland-input.c.orig	2023-03-29 12:26:36.000000000 +0000
+++ hw/xwayland/xwayland-input.c
@@ -26,7 +26,18 @@
 
 #include <xwayland-config.h>
 
+#ifdef __Linux__
 #include <linux/input.h>
+#else
+#define BTN_LEFT 1
+#define BTN_MIDDLE 2
+#define BTN_RIGHT 3
+#define BTN_SIDE 4
+#define KEY_LEFTSHIFT 5
+#define KEY_RIGHTSHIFT 6
+#define KEY_LEFTCTRL 7
+#define KEY_RIGHTCTRL 8
+#endif
 #include <sys/mman.h>
 
 #include <inputstr.h>
