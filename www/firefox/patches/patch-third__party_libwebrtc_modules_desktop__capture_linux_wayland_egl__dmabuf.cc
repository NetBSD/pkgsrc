$NetBSD: patch-third__party_libwebrtc_modules_desktop__capture_linux_wayland_egl__dmabuf.cc,v 1.4 2025/11/14 17:17:18 ryoon Exp $

--- third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc.orig	2025-10-31 13:10:50.000000000 +0000
+++ third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
@@ -15,7 +15,9 @@
 #include <EGL/eglplatform.h>
 #include <GL/gl.h>
 #include <GL/glext.h>
+#if defined(__linux__)
 #include <asm/ioctl.h>
+#endif
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <gbm.h>
