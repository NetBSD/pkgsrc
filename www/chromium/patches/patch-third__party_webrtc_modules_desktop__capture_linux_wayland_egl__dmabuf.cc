$NetBSD: patch-third__party_webrtc_modules_desktop__capture_linux_wayland_egl__dmabuf.cc,v 1.1 2025/02/06 09:58:29 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
@@ -10,11 +10,15 @@
 
 #include "modules/desktop_capture/linux/wayland/egl_dmabuf.h"
 
+#if !defined(WEBRTC_BSD)
 #include <asm/ioctl.h>
+#endif
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <libdrm/drm_fourcc.h>
+#if !defined(WEBRTC_BSD)
 #include <linux/types.h>
+#endif
 #include <spa/param/video/format-utils.h>
 #include <unistd.h>
 #include <xf86drm.h>
