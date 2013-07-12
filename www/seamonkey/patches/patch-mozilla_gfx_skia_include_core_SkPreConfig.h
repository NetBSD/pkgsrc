$NetBSD: patch-mozilla_gfx_skia_include_core_SkPreConfig.h,v 1.1 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/gfx/skia/include/core/SkPreConfig.h.orig	2013-06-20 04:35:03.000000000 +0000
+++ mozilla/gfx/skia/include/core/SkPreConfig.h
@@ -94,7 +94,7 @@
 //////////////////////////////////////////////////////////////////////
 
 #if !defined(SK_CPU_BENDIAN) && !defined(SK_CPU_LENDIAN)
-#if defined (__ppc__) || defined(__PPC__) || defined(__ppc64__) || defined(__PPC64__)
+#if defined (__ppc__) || defined(__PPC__) || defined(__ppc64__) || defined(__PPC64__) || defined(__sparc) || defined(__sparc__)
         #define SK_CPU_BENDIAN
     #else
         #define SK_CPU_LENDIAN
