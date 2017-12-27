$NetBSD: patch-src_backend_bsd.c,v 1.1 2017/12/27 14:13:55 wiz Exp $

Adapt for NetBSD-8.99.9.

--- src/backend_bsd.c.orig	2017-12-27 12:38:30.270838738 +0100
+++ src/backend_bsd.c	2017-12-27 12:39:31.650117455 +0100
@@ -44,6 +44,9 @@
 #include <usbhid.h>
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
+#ifdef HAVE_DEV_HID_HID_H
+    #include <dev/hid/hid.h>
+#endif
 #ifdef HAVE_DEV_USB_USB_IOCTL_H
     #include <dev/usb/usb_ioctl.h>
 #endif
