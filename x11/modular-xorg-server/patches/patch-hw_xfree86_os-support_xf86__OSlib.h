$NetBSD: patch-hw_xfree86_os-support_xf86__OSlib.h,v 1.1 2013/05/18 08:29:04 obache Exp $

* treat DragonFly same as newer FreeBSD.

--- hw/xfree86/os-support/xf86_OSlib.h.orig	2012-05-17 17:09:03.000000000 +0000
+++ hw/xfree86/os-support/xf86_OSlib.h
@@ -277,7 +277,7 @@ struct pcvtid {
 #include <dev/wscons/wsdisplay_usl_io.h>
 #endif                          /* WSCONS_SUPPORT */
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
-#if defined(__FreeBSD_kernel_version) && (__FreeBSD_kernel_version >= 500013)
+#if defined(__FreeBSD_kernel_version) && (__FreeBSD_kernel_version >= 500013) || defined(__DragonFly__)
 #include <sys/mouse.h>
 #else
 #undef MOUSE_GETINFO
