$NetBSD: patch-glfw_wl__inject.c,v 1.1 2026/09/24 19:19:26 ktnb Exp $

Don't assume linux

--- glfw/wl_inject.c.orig	2026-09-21 14:16:52.703734340 +0000
+++ glfw/wl_inject.c
@@ -15,7 +15,7 @@
 #include <time.h>
 #include <unistd.h>
 #include <string.h>
-#include <linux/input-event-codes.h>
+#include "evdev_keycodes.h"
 
 GLFWAPI bool
 glfwWaylandCreateVirtualDevices(void) {
