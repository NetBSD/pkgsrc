$NetBSD: patch-mozglue_misc_SIMD.cpp,v 1.1 2022/10/08 21:18:55 ryoon Exp $

Fix build under NetBSD/i386 9 with GCC.
From: https://bugzilla.mozilla.org/show_bug.cgi?id=1792158

--- mozglue/misc/SIMD.cpp.orig	2022-10-07 15:25:41.000000000 +0000
+++ mozglue/misc/SIMD.cpp
@@ -439,8 +439,27 @@ const char* SIMD::memchr8SSE2(const char
   return reinterpret_cast<const char*>(uresult);
 }
 
+// So, this is a bit awkward. It generally simplifies things if we can just
+// assume all the AVX2 code is 64-bit, so we have this preprocessor guard
+// in SIMD_avx2 over all of its actual code, and it also defines versions
+// of its endpoints that just assert false if the guard is not satisfied.
+// A 32 bit processor could implement the AVX2 instruction set though, which
+// would result in it passing the supports_avx2() check and landing in an
+// assertion failure. Accordingly, we just don't allow that to happen. We
+// are not particularly concerned about ensuring that newer 32 bit processors
+// get access to the AVX2 functions exposed here.
+#  if defined(MOZILLA_MAY_SUPPORT_AVX2) && defined(__x86_64__)
+
+bool SupportsAVX2() { return supports_avx2(); }
+
+#  else
+
+bool SupportsAVX2() { return false; }
+
+#  endif
+
 const char* SIMD::memchr8(const char* ptr, char value, size_t length) {
-  if (supports_avx2()) {
+  if (SupportsAVX2()) {
     return memchr8AVX2(ptr, value, length);
   }
   return memchr8SSE2(ptr, value, length);
@@ -453,7 +472,7 @@ const char16_t* SIMD::memchr16SSE2(const
 
 const char16_t* SIMD::memchr16(const char16_t* ptr, char16_t value,
                                size_t length) {
-  if (supports_avx2()) {
+  if (SupportsAVX2()) {
     return memchr16AVX2(ptr, value, length);
   }
   return memchr16SSE2(ptr, value, length);
@@ -461,7 +480,7 @@ const char16_t* SIMD::memchr16(const cha
 
 const uint64_t* SIMD::memchr64(const uint64_t* ptr, uint64_t value,
                                size_t length) {
-  if (supports_avx2()) {
+  if (SupportsAVX2()) {
     return memchr64AVX2(ptr, value, length);
   }
   return FindInBufferNaive<uint64_t>(ptr, value, length);
