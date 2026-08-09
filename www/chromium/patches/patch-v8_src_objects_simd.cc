$NetBSD: patch-v8_src_objects_simd.cc,v 1.3 2026/08/09 06:31:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/objects/simd.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ v8/src/objects/simd.cc
@@ -348,7 +348,7 @@ uintptr_t fast_search_avx(T* array, uint
 }
 #endif  // ifdef __SSE3__
 
-#ifdef NEON64
+#if defined(NEON64) && !defined(V8_TARGET_OS_OPENBSD)
 
 template <typename ScalarType>
 struct SVEOperations {
@@ -638,9 +638,11 @@ template <typename T>
 inline uintptr_t search(T* array, uintptr_t array_len, uintptr_t index,
                         T search_element) {
 #ifdef NEON64
+#ifndef V8_TARGET_OS_OPENBSD
   if (get_vectorization_kind() == SimdKinds::kSVE) {
     return fast_search_sve(array, array_len, index, search_element);
   }
+#endif
 #else
   if (get_vectorization_kind() == SimdKinds::kAVX2) {
     return fast_search_avx(array, array_len, index, search_element);
