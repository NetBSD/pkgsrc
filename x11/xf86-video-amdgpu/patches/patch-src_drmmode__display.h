$NetBSD: patch-src_drmmode__display.h,v 1.1 2025/08/08 11:28:14 wiz Exp $

https://gitlab.freedesktop.org/xorg/driver/xf86-video-amdgpu/-/issues/84

--- src/drmmode_display.h.orig	2025-08-08 11:23:17.935590246 +0000
+++ src/drmmode_display.h
@@ -28,7 +28,7 @@
 #define DRMMODE_DISPLAY_H
 
 #include "xf86drmMode.h"
-#ifdef HAVE_LIBUDEV
+#if HAVE_LIBUDEV
 #include "libudev.h"
 #endif
 
