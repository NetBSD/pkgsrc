$NetBSD: patch-third__party_webrtc_modules_desktop__capture_linux_x11_x__server__pixel__buffer.cc,v 1.14 2026/01/19 16:14:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/modules/desktop_capture/linux/x11/x_server_pixel_buffer.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/webrtc/modules/desktop_capture/linux/x11/x_server_pixel_buffer.cc
@@ -212,6 +212,12 @@ bool XServerPixelBuffer::Init(XAtomCache
 void XServerPixelBuffer::InitShm(const XWindowAttributes& attributes) {
   Visual* default_visual = attributes.visual;
   int default_depth = attributes.depth;
+#if defined(__OpenBSD__)
+// pledge(2)
+  RTC_LOG(LS_WARNING) << "Unable to use shmget(2) while using pledge(2). "
+                         "Performance may be degraded.";
+  return;
+#endif
 
   int major, minor;
   Bool have_pixmaps;
