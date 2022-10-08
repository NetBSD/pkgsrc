$NetBSD: patch-mozglue_misc_SIMD__avx2.cpp,v 1.1 2022/10/08 21:18:55 ryoon Exp $

Fix build under NetBSD/i386 9 with GCC.
From: https://bugzilla.mozilla.org/show_bug.cgi?id=1792158

--- mozglue/misc/SIMD_avx2.cpp.orig	2022-10-07 15:25:41.000000000 +0000
+++ mozglue/misc/SIMD_avx2.cpp
@@ -8,7 +8,10 @@
 #include "mozilla/SSE.h"
 #include "mozilla/Assertions.h"
 
-#ifdef MOZILLA_MAY_SUPPORT_AVX2
+// Restricting to x86_64 simplifies things, and we're not particularly
+// worried about slightly degraded performance on 32 bit processors which
+// support AVX2, as this should be quite a minority.
+#if defined(MOZILLA_MAY_SUPPORT_AVX2) && defined(__x86_64__)
 
 #  include <cstring>
 #  include <immintrin.h>
