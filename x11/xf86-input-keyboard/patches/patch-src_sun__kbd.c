$NetBSD: patch-src_sun__kbd.c,v 1.4 2025/04/22 15:45:04 nia Exp $

Add missing includes for NBBY, ioctl.

--- src/sun_kbd.c.orig	2025-04-22 15:42:15.259362430 +0000
+++ src/sun_kbd.c
@@ -56,6 +56,8 @@
 #include "xf86OSKbd.h"
 #include "sun_kbd.h"
 
+#include <sys/types.h>
+#include <sys/ioctl.h>
 #include <sys/stropts.h>
 #include <sys/vuid_event.h>
 #include <sys/kbd.h>
