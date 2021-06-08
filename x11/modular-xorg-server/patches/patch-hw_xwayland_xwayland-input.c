$NetBSD: patch-hw_xwayland_xwayland-input.c,v 1.3 2021/06/08 22:51:11 khorben Exp $

Fix build on Solaris 10/amd64 (from pkg/56169)
Support non-evdev platforms.

--- hw/xwayland/xwayland-input.c.orig	2021-04-13 14:11:40.000000000 +0000
+++ hw/xwayland/xwayland-input.c
@@ -26,7 +26,22 @@
 
 #include "xwayland.h"
 
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat/config.h>
+#include <nbcompat/cdefs.h>
+#include <nbcompat/string.h>
+#else
+#include <string.h>
+#endif
+
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
