$NetBSD: patch-src_3rdparty_chromium_third__party_abseil-cpp_absl_base_config.h,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/abseil-cpp/absl/base/config.h.orig	2022-03-12 18:01:41.477106354 +0000
+++ src/3rdparty/chromium/third_party/abseil-cpp/absl/base/config.h
@@ -362,6 +362,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_MMAP
 #error ABSL_HAVE_MMAP cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) ||   \
+    defined(__NetBSD__) || \
     defined(__ros__) || defined(__native_client__) || defined(__asmjs__) || \
     defined(__wasm__) || defined(__Fuchsia__) || defined(__sun) || \
     defined(__ASYLO__)
@@ -375,6 +376,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_PTHREAD_GETSCHEDPARAM
 #error ABSL_HAVE_PTHREAD_GETSCHEDPARAM cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__) || \
     defined(__ros__)
 #define ABSL_HAVE_PTHREAD_GETSCHEDPARAM 1
 #endif
