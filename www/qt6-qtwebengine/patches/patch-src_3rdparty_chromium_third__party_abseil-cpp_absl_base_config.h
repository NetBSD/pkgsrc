$NetBSD: patch-src_3rdparty_chromium_third__party_abseil-cpp_absl_base_config.h,v 1.2 2026/04/30 06:39:43 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/abseil-cpp/absl/base/config.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/abseil-cpp/absl/base/config.h
@@ -409,7 +409,8 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_SCHED_YIELD
 #error ABSL_HAVE_SCHED_YIELD cannot be directly set
 #elif defined(__linux__) || defined(__ros__) || defined(__native_client__) || \
-    defined(__VXWORKS__)
+    defined(__VXWORKS__) || defined(__OpenBSD__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__)
 #define ABSL_HAVE_SCHED_YIELD 1
 #endif
 
@@ -424,7 +425,8 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 // platforms.
 #ifdef ABSL_HAVE_SEMAPHORE_H
 #error ABSL_HAVE_SEMAPHORE_H cannot be directly set
-#elif defined(__linux__) || defined(__ros__) || defined(__VXWORKS__)
+#elif defined(__linux__) || defined(__ros__) || defined(__VXWORKS__) || \
+    defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #define ABSL_HAVE_SEMAPHORE_H 1
 #endif
 
