$NetBSD: patch-third__party_webrtc_modules_desktop__capture_linux_x11_x__server__pixel__buffer.h,v 1.4 2026/08/09 06:31:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/modules/desktop_capture/linux/x11/x_server_pixel_buffer.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/webrtc/modules/desktop_capture/linux/x11/x_server_pixel_buffer.h
@@ -17,6 +17,10 @@
 #include <X11/Xlib.h>
 #include <X11/extensions/XShm.h>
 
+#if defined(__OpenBSD__)
+#include <xcb/xcb.h>
+#endif
+
 #include <cstdint>
 #include <vector>
 
@@ -84,6 +88,11 @@ class XServerPixelBuffer {
   bool xshm_attached_ = false;
   bool xshm_get_image_succeeded_ = false;
   std::vector<uint8_t> icc_profile_;
+
+#if defined(__OpenBSD__)
+  size_t shm_size_ = 0;
+  xcb_connection_t* xcb_connection_ = nullptr;
+#endif
 };
 
 }  // namespace webrtc
