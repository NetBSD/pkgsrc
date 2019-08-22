$NetBSD: patch-hw_xwayland_xwayland-input.c,v 1.1 2019/08/22 13:12:31 nia Exp $

Support non-evdev platforms.

--- hw/xwayland/xwayland-input.c.orig	2019-02-26 19:28:50.000000000 +0000
+++ hw/xwayland/xwayland-input.c
@@ -26,7 +26,14 @@
 
 #include "xwayland.h"
 
+#if defined(__linux) || defined(__FreeBSD__)
 #include <linux/input.h>
+#else
+#define BTN_LEFT	(0)
+#define BTN_MIDDLE	(1)
+#define BTN_RIGHT	(2)
+#define BTN_SIDE	(3)
+#endif
 
 #include <sys/mman.h>
 #include <xkbsrv.h>
