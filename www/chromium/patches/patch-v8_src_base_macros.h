$NetBSD: patch-v8_src_base_macros.h,v 1.1 2026/05/10 15:30:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/macros.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ v8/src/base/macros.h
@@ -224,7 +224,7 @@ V8_INLINE constexpr Dest bit_cast(Source
 
 // Define V8_USE_UNDEFINED_BEHAVIOR_SANITIZER macro.
 #if defined(__has_feature)
-#if __has_feature(undefined_behavior_sanitizer)
+#if __has_feature(undefined_behavior_sanitizer) && !defined(V8_OS_BSD)
 #define V8_USE_UNDEFINED_BEHAVIOR_SANITIZER 1
 #endif
 #endif
