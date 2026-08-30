$NetBSD: patch-Source_ThirdParty_skia_src_gpu_ganesh_GrAutoLocaleSetter.h,v 1.1 2026/08/30 14:25:05 wiz Exp $

No uselocale() on NetBSD.

--- Source/ThirdParty/skia/src/gpu/ganesh/GrAutoLocaleSetter.h.orig	2024-11-02 08:05:09.263557564 +0000
+++ Source/ThirdParty/skia/src/gpu/ganesh/GrAutoLocaleSetter.h
@@ -27,7 +27,7 @@
 #define HAVE_XLOCALE 0
 #endif
 
-#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION)
+#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION) || defined(__NetBSD__)
 #define HAVE_LOCALE_T 0
 #else
 #define HAVE_LOCALE_T 1
