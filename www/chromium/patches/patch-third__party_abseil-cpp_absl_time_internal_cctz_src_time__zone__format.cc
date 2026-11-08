$NetBSD: patch-third__party_abseil-cpp_absl_time_internal_cctz_src_time__zone__format.cc,v 1.32 2026/11/08 15:39:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/abseil-cpp/absl/time/internal/cctz/src/time_zone_format.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ third_party/abseil-cpp/absl/time/internal/cctz/src/time_zone_format.cc
@@ -22,7 +22,7 @@
 
 #if HAS_STRPTIME
 #if !defined(_XOPEN_SOURCE) && !defined(__FreeBSD__) && \
-    !defined(__OpenBSD__) && !defined(__APPLE__)
+    !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__APPLE__)
 #define _XOPEN_SOURCE 500  // Exposes definitions for SUSv2 (UNIX 98).
 #endif
 #endif
