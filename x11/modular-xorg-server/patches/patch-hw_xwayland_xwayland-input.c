$NetBSD: patch-hw_xwayland_xwayland-input.c,v 1.2 2019/10/29 22:46:39 nia Exp $

Support non-evdev platforms.

--- hw/xwayland/xwayland-input.c.orig	2019-02-26 19:28:50.000000000 +0000
+++ hw/xwayland/xwayland-input.c
@@ -26,7 +26,14 @@
 
 #include "xwayland.h"
 
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <linux/input.h>
+#else
+#define BTN_LEFT	(0x110)
+#define BTN_RIGHT	(0x111)
+#define BTN_MIDDLE	(0x112)
+#define BTN_SIDE	(0x113)
+#endif
 
 #include <sys/mman.h>
 #include <xkbsrv.h>
