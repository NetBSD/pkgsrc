$NetBSD: patch-third__party_abseil-cpp_absl_base_internal_raw__logging.cc,v 1.25 2026/09/02 13:13:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/abseil-cpp/absl/base/internal/raw_logging.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/abseil-cpp/absl/base/internal/raw_logging.cc
@@ -43,7 +43,7 @@
 // this, consider moving both to config.h instead.
 #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) ||     \
     defined(__hexagon__) || defined(__Fuchsia__) || defined(__OpenBSD__) || \
-    defined(__EMSCRIPTEN__) || defined(__ASYLO__)
+    defined(__EMSCRIPTEN__) || defined(__ASYLO__) || defined(__NetBSD__)
 
 #include <unistd.h>
 
