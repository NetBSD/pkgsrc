$NetBSD: patch-v8_src_objects_simd.cc,v 1.5 2026/09/22 13:41:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/objects/simd.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ v8/src/objects/simd.cc
@@ -350,7 +350,7 @@ uintptr_t fast_search_avx(T* array, uint
 
 // When built with other toolchains, do not count on it to expose
 // __builtin_sve_* on a per-function basis. Fallback to Neon.
-#if defined(NEON64) && defined(__clang__)
+#if defined(NEON64) && defined(__clang__) && !defined(__OpenBSD__)
 #define V8_ENABLE_SIMD_SVE 1
 
 template <typename ScalarType>
