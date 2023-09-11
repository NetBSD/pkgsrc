$NetBSD: patch-third__party_libwebrtc_modules_desktop__capture_linux_wayland_egl__dmabuf.cc,v 1.1 2023/09/11 12:33:25 ryoon Exp $

--- third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc.orig	2023-03-30 21:16:09.000000000 +0000
+++ third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
@@ -10,12 +10,16 @@
 
 #include "modules/desktop_capture/linux/wayland/egl_dmabuf.h"
 
+#if defined(__linux__)
 #include <asm/ioctl.h>
+#endif
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <gdk/gdk.h>
 #include <libdrm/drm_fourcc.h>
+#if defined(__linux__)
 #include <linux/types.h>
+#endif
 #include <spa/param/video/format-utils.h>
 #include <unistd.h>
 #include <xf86drm.h>
