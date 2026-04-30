$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_modules_portal_pipewire__utils.h,v 1.1 2026/04/30 06:39:44 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/webrtc/modules/portal/pipewire_utils.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/modules/portal/pipewire_utils.h
@@ -11,7 +11,9 @@
 #ifndef MODULES_PORTAL_PIPEWIRE_UTILS_H_
 #define MODULES_PORTAL_PIPEWIRE_UTILS_H_
 
+#if defined(__linux__)
 #include <asm-generic/ioctl.h>
+#endif
 #include <sys/ioctl.h>
 #include <sys/mman.h>
 
