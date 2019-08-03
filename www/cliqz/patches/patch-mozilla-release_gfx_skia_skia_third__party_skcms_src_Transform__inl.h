$NetBSD: patch-mozilla-release_gfx_skia_skia_third__party_skcms_src_Transform__inl.h,v 1.1 2019/08/03 07:18:18 fox Exp $

Fixes the internal compiler error in skia Transform_inl.h

This happens for MIPS 64 and GCC as documented in the code section,
this has been extended for checks in s390x and the i*86 platforms.

https://bugzilla.mozilla.org/show_bug.cgi?id=1562886

PS: Probably remove this once upstream gcc fixes the issue.

--- mozilla-release/gfx/skia/skia/third_party/skcms/src/Transform_inl.h.orig	2019-08-02 17:49:51.197475983 +0000
+++ mozilla-release/gfx/skia/skia/third_party/skcms/src/Transform_inl.h
@@ -559,7 +559,8 @@ SI void sample_clut_16(const skcms_A2B* 
 
 // GCC 7.2.0 hits an internal compiler error with -finline-functions (or -O3)
 // when targeting MIPS 64,  I think attempting to inline clut() into exec_ops().
-#if 1 && defined(__GNUC__) && !defined(__clang__) && defined(__mips64)
+// s390x and i*86 also hit this with GCC 7.4 and -O2
+#if 1 && defined(__GNUC__) && !defined(__clang__) && ( defined(__mips64) || defined(__s390x__) || defined( __i586__ ) || defined( __i486__ ) || defined( __i386__ ))
     #define MAYBE_NOINLINE __attribute__((noinline))
 #else
     #define MAYBE_NOINLINE
