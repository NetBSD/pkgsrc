$NetBSD: patch-third__party_skia_src_core_SkAutoLocaleSetter.h,v 1.1 2026/08/09 06:31:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/skia/src/core/SkAutoLocaleSetter.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/skia/src/core/SkAutoLocaleSetter.h
@@ -15,7 +15,7 @@
 #include <string>
 #endif
 
-#if !defined(SK_BUILD_FOR_ANDROID)
+#if !defined(SK_BUILD_FOR_ANDROID) && !defined(__NetBSD__)
 #include <locale.h>
 #endif
 
@@ -27,7 +27,7 @@
 #define HAVE_XLOCALE 0
 #endif
 
-#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION)
+#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION) || defined(__NetBSD__)
 #define HAVE_LOCALE_T 0
 #else
 #define HAVE_LOCALE_T 1
