$NetBSD: patch-gfx__skia__include__core__SkPreConfig.h,v 1.1 2013/11/03 04:51:59 ryoon Exp $

Configure sparc cpus as big endian (Bugzilla #884376)

diff -r 581ea0e6531e gfx/skia/include/core/SkPreConfig.h
--- gfx/skia/include/core/SkPreConfig.h	Tue May 07 09:47:43 2013 -0400
+++ gfx/skia/include/core/SkPreConfig.h	Tue Jun 18 17:36:55 2013 +0200
@@ -94,7 +94,7 @@
 //////////////////////////////////////////////////////////////////////
 
 #if !defined(SK_CPU_BENDIAN) && !defined(SK_CPU_LENDIAN)
-#if defined (__ppc__) || defined(__PPC__) || defined(__ppc64__) || defined(__PPC64__)
+#if defined (__ppc__) || defined(__PPC__) || defined(__ppc64__) || defined(__PPC64__) || defined(__sparc) || defined(__sparc__)
         #define SK_CPU_BENDIAN
     #else
         #define SK_CPU_LENDIAN
