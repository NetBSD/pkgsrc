$NetBSD: patch-third__party_libwebrtc_modules_desktop__capture_linux_wayland_egl__dmabuf.cc,v 1.1 2023/04/05 14:22:36 ryoon Exp $

--- third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc.orig	2023-03-02 21:15:55.000000000 +0000
+++ third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
@@ -10,11 +10,15 @@
 
 #include "modules/desktop_capture/linux/wayland/egl_dmabuf.h"
 
+#if defined(__linux__)
 #include <asm/ioctl.h>
+#endif
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <libdrm/drm_fourcc.h>
+#if defined(__linux__)
 #include <linux/types.h>
+#endif
 #include <spa/param/video/format-utils.h>
 #include <unistd.h>
 #include <xf86drm.h>
