$NetBSD: patch-third__party_abseil-cpp_absl_base_internal_raw__logging.cc,v 1.19 2026/05/10 15:30:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/abseil-cpp/absl/base/internal/raw_logging.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ third_party/abseil-cpp/absl/base/internal/raw_logging.cc
@@ -43,7 +43,7 @@
 // this, consider moving both to config.h instead.
 #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) ||     \
     defined(__hexagon__) || defined(__Fuchsia__) || defined(__OpenBSD__) || \
-    defined(__EMSCRIPTEN__) || defined(__ASYLO__)
+    defined(__EMSCRIPTEN__) || defined(__ASYLO__) || defined(__NetBSD__)
 
 #include <unistd.h>
 
