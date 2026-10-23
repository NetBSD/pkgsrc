$NetBSD: patch-v8_src_objects_simd.cc,v 1.10 2026/10/23 15:05:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/objects/simd.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ v8/src/objects/simd.cc
@@ -353,7 +353,7 @@ uintptr_t fast_search_avx(T* array, uint
 // mangling SVE types with the Microsoft C++ ABI since version 21.
 // Fallback to Neon in cases where SVE is not supported.
 #if defined(NEON64) && defined(__clang__) && \
-    (!defined(V8_TARGET_OS_WIN) || __clang_major__ >= 21)
+    (!defined(V8_TARGET_OS_WIN) || __clang_major__ >= 21) && !defined(__OpenBSD__)
 #define V8_ENABLE_SIMD_SVE 1
 
 template <typename ScalarType>
