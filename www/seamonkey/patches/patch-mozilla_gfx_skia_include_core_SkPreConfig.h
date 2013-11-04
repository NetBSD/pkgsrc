$NetBSD: patch-mozilla_gfx_skia_include_core_SkPreConfig.h,v 1.2 2013/11/04 06:01:46 ryoon Exp $

--- mozilla/gfx/skia/include/core/SkPreConfig.h.orig	2013-10-29 01:20:49.000000000 +0000
+++ mozilla/gfx/skia/include/core/SkPreConfig.h
@@ -100,7 +100,7 @@
 
 #if !defined(SK_CPU_BENDIAN) && !defined(SK_CPU_LENDIAN)
     #if defined (__ppc__) || defined(__PPC__) || defined(__ppc64__) \
-        || defined(__PPC64__)
+        || defined(__PPC64__) || defined(__sparc) || defined(__sparc__)
         #define SK_CPU_BENDIAN
     #else
         #define SK_CPU_LENDIAN
