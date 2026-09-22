$NetBSD: patch-Source_ThirdParty_skia_src_core_SkAutoLocaleSetter.h,v 1.1 2026/09/22 12:27:02 wiz Exp $

No uselocale() on NetBSD.

--- Source/ThirdParty/skia/src/core/SkAutoLocaleSetter.h.orig	2026-09-16 20:30:24.311812753 +0000
+++ Source/ThirdParty/skia/src/core/SkAutoLocaleSetter.h
@@ -27,7 +27,7 @@
 #define HAVE_XLOCALE 0
 #endif
 
-#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION)
+#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION) || defined(__NetBSD__)
 #define HAVE_LOCALE_T 0
 #else
 #define HAVE_LOCALE_T 1
