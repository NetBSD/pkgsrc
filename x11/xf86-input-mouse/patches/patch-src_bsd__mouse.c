$NetBSD: patch-src_bsd__mouse.c,v 1.1 2013/06/16 02:05:20 obache Exp $

* enable MSE_MISC on netbsd as well, otherwise we can't find WSMouse.

--- src/bsd_mouse.c.orig	2012-10-08 01:40:07.000000000 +0000
+++ src/bsd_mouse.c
@@ -98,7 +98,7 @@ static int
 SupportedInterfaces(void)
 {
 #if defined(__NetBSD__)
-    return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_AUTO;
+    return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_AUTO | MSE_MISC;
 #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
     return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_AUTO | MSE_MISC;
 #else
