$NetBSD: patch-src_3rdparty_chromium_third__party_perfetto_include_perfetto_ext_base_event__fd.h,v 1.1 2025/12/21 09:38:43 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/event_fd.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/event_fd.h
@@ -55,6 +55,8 @@ class EventFd {
   // On Mac and other non-Linux UNIX platforms a pipe-based fallback is used.
   // The write end of the wakeup pipe.
   ScopedFile write_fd_;
+#else
+  ScopedFile write_fd_;
 #endif
 };
 
