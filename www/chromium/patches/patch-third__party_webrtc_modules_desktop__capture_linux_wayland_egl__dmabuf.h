$NetBSD: patch-third__party_webrtc_modules_desktop__capture_linux_wayland_egl__dmabuf.h,v 1.1 2026/02/15 09:04:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.h
@@ -16,6 +16,8 @@
 #include <GL/gl.h>
 #include <gbm.h>
 
+#include <sys/types.h>
+
 #include <cstdint>
 #include <map>
 #include <memory>
