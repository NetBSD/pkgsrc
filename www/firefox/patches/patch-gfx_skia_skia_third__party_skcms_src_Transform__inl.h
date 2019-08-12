$NetBSD: patch-gfx_skia_skia_third__party_skcms_src_Transform__inl.h,v 1.1 2019/08/12 01:04:38 tsutsui Exp $

- pull upstream change to fix ICE on NetBSD/i386 8.1 build (PR pkg/54383)
 https://hg.mozilla.org/releases/mozilla-esr68/rev/420c07d42512

--- gfx/skia/skia/third_party/skcms/src/Transform_inl.h.orig	2019-07-17 20:51:26.000000000 +0000
+++ gfx/skia/skia/third_party/skcms/src/Transform_inl.h
@@ -559,7 +559,7 @@ SI void sample_clut_16(const skcms_A2B* 
 
 // GCC 7.2.0 hits an internal compiler error with -finline-functions (or -O3)
 // when targeting MIPS 64,  I think attempting to inline clut() into exec_ops().
-#if 1 && defined(__GNUC__) && !defined(__clang__) && defined(__mips64)
+#if 1 && defined(__GNUC__) && !defined(__clang__) && (defined(__mips64) || defined(__s390x__) || defined(__i586__) || defined(__i486__) || defined(__i386__))
     #define MAYBE_NOINLINE __attribute__((noinline))
 #else
     #define MAYBE_NOINLINE
