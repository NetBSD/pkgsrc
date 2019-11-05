$NetBSD: patch-src_hardwareintegration_compositor_linux-dmabuf-unstable-v1_linuxdmabuf.h,v 1.1 2019/11/05 15:29:35 adam Exp $

Add missing #include.

--- src/hardwareintegration/compositor/linux-dmabuf-unstable-v1/linuxdmabuf.h.orig	2019-11-05 15:25:42.917834520 +0000
+++ src/hardwareintegration/compositor/linux-dmabuf-unstable-v1/linuxdmabuf.h
@@ -54,6 +54,8 @@
 #include <EGL/egl.h>
 #include <EGL/eglext.h>
 
+#include <array>
+
 // compatibility with libdrm <= 2.4.74
 #ifndef DRM_FORMAT_RESERVED
 #define DRM_FORMAT_RESERVED           ((1ULL << 56) - 1)
