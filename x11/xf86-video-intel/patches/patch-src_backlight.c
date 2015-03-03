$NetBSD: patch-src_backlight.c,v 1.1 2015/03/03 01:02:05 khorben Exp $

--- src/backlight.c.orig	2014-11-18 21:50:39.000000000 +0000
+++ src/backlight.c
@@ -84,7 +84,7 @@ void backlight_init(struct backlight *b)
 	b->has_power = 0;
 }
 
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 
 #include <dev/wscons/wsconsio.h>
 #include <xf86Priv.h>
