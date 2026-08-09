$NetBSD: patch-v8_src_base_macros.h,v 1.6 2026/08/09 06:31:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/macros.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ v8/src/base/macros.h
@@ -224,7 +224,7 @@ V8_INLINE constexpr Dest bit_cast(Source
 
 // Define V8_USE_UNDEFINED_BEHAVIOR_SANITIZER macro.
 #if defined(__has_feature)
-#if __has_feature(undefined_behavior_sanitizer)
+#if __has_feature(undefined_behavior_sanitizer) && !defined(V8_OS_BSD)
 #define V8_USE_UNDEFINED_BEHAVIOR_SANITIZER 1
 #endif
 #endif
