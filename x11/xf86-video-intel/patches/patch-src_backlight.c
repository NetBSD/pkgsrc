$NetBSD: patch-src_backlight.c,v 1.2 2015/05/22 05:40:36 richard Exp $

SunOS needs <sys/mkdev.h> for major()

--- src/backlight.c.orig	2014-11-18 21:50:39.000000000 +0000
+++ src/backlight.c
@@ -49,6 +49,9 @@
 
 #include "backlight.h"
 #include "fd.h"
+#ifdef __sun
+#include <sys/mkdev.h>
+#endif
 
 #define BACKLIGHT_CLASS "/sys/class/backlight"
 
@@ -84,7 +87,7 @@ void backlight_init(struct backlight *b)
 	b->has_power = 0;
 }
 
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 
 #include <dev/wscons/wsconsio.h>
 #include <xf86Priv.h>
