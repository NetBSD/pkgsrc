$NetBSD: patch-src_sun__mouse.c,v 1.1 2015/04/06 13:28:22 tnn Exp $

--- src/sun_mouse.c.orig	2014-08-12 06:36:34.000000000 +0000
+++ src/sun_mouse.c
@@ -51,6 +51,10 @@
 #include <xorg-config.h>
 #endif
 
+#include <unistd.h> /* for ioctl(2) */
+#include <sys/stropts.h>
+#include <sys/vuid_event.h>
+#include <sys/msio.h>
 #include "xorg-server.h"
 #include "xf86.h"
 #include "xf86_OSlib.h"
@@ -58,9 +62,6 @@
 #include "xisb.h"
 #include "mipointer.h"
 #include "xf86Crtc.h"
-#include <sys/stropts.h>
-#include <sys/vuid_event.h>
-#include <sys/msio.h>
 
 /* Wheel mouse support in VUID drivers in Solaris 9 updates & Solaris 10 */
 #ifdef WHEEL_DEVID /* Defined in vuid_event.h if VUID wheel support present */
