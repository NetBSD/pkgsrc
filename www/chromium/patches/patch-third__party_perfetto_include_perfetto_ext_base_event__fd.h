$NetBSD: patch-third__party_perfetto_include_perfetto_ext_base_event__fd.h,v 1.23 2026/07/08 13:42:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/include/perfetto/ext/base/event_fd.h.orig	2026-07-06 22:58:46.000000000 +0000
+++ third_party/perfetto/include/perfetto/ext/base/event_fd.h
@@ -58,6 +58,8 @@ class EventFd {
   // On Mac and other non-Linux UNIX platforms a pipe-based fallback is used.
   // The write end of the wakeup pipe.
   ScopedFile write_fd_;
+#else
+  ScopedFile write_fd_;
 #endif
 };
 
