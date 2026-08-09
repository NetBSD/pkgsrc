$NetBSD: patch-third__party_webrtc_modules_desktop__capture_linux_wayland_egl__dmabuf.cc,v 1.24 2026/08/09 06:31:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
@@ -15,14 +15,18 @@
 #include <EGL/eglplatform.h>
 #include <GL/gl.h>
 #include <GL/glext.h>
+#if !defined(WEBRTC_BSD)
 #include <asm/ioctl.h>
+#endif
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <gbm.h>
 #include <libdrm/drm_fourcc.h>
 #include <spa/param/video/raw.h>
 #include <sys/stat.h>
+#if !defined(WEBRTC_BSD)
 #include <sys/sysmacros.h>
+#endif
 #include <sys/types.h>
 #include <unistd.h>
 #include <xf86drm.h>
