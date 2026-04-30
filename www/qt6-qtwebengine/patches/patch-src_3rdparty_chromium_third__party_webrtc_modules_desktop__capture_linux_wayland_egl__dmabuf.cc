$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_modules_desktop__capture_linux_wayland_egl__dmabuf.cc,v 1.2 2026/04/30 06:39:44 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
@@ -15,7 +15,9 @@
 #include <EGL/eglplatform.h>
 #include <GL/gl.h>
 #include <GL/glext.h>
+#if !defined(WEBRTC_BSD)
 #include <asm/ioctl.h>
+#endif
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <gbm.h>
