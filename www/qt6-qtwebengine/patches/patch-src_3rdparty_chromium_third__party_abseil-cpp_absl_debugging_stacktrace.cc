$NetBSD: patch-src_3rdparty_chromium_third__party_abseil-cpp_absl_debugging_stacktrace.cc,v 1.1 2026/04/30 06:39:43 adam Exp $

NetBSD has alloca() but not <alloca.h>

--- src/3rdparty/chromium/third_party/abseil-cpp/absl/debugging/stacktrace.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/abseil-cpp/absl/debugging/stacktrace.cc
@@ -55,6 +55,8 @@
 #ifdef _WIN32
 #include <malloc.h>
 #define ABSL_INTERNAL_HAVE_ALLOCA 1
+#elif defined(__NetBSD__)
+#define ABSL_INTERNAL_HAVE_ALLOCA 1
 #else
 #ifdef __has_include
 #if __has_include(<alloca.h>)
