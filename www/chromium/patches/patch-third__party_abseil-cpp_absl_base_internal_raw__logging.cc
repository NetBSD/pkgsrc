$NetBSD: patch-third__party_abseil-cpp_absl_base_internal_raw__logging.cc,v 1.1 2025/02/06 09:58:22 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/abseil-cpp/absl/base/internal/raw_logging.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/abseil-cpp/absl/base/internal/raw_logging.cc
@@ -44,7 +44,7 @@
 #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
     defined(__hexagon__) || defined(__Fuchsia__) ||                     \
     defined(__native_client__) || defined(__OpenBSD__) ||               \
-    defined(__EMSCRIPTEN__) || defined(__ASYLO__)
+    defined(__EMSCRIPTEN__) || defined(__ASYLO__) || defined(__NetBSD__)
 
 #include <unistd.h>
 
