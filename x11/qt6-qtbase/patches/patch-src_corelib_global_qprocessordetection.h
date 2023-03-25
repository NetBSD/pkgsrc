$NetBSD: patch-src_corelib_global_qprocessordetection.h,v 1.1 2023/03/25 07:29:32 nros Exp $

* Enable Alpha support
  From upstream:
  https://codereview.qt-project.org/c/qt/qtbase/+/437349

--- src/corelib/global/qprocessordetection.h.orig	2023-03-23 21:53:15.312590294 +0000
+++ src/corelib/global/qprocessordetection.h
@@ -48,8 +48,8 @@
 
     Alpha is bi-endian, use endianness auto-detection implemented below.
 */
-// #elif defined(__alpha__) || defined(_M_ALPHA)
-// #  define Q_PROCESSOR_ALPHA
+#if defined(__alpha__) || defined(_M_ALPHA)
+#  define Q_PROCESSOR_ALPHA
 // Q_BYTE_ORDER not defined, use endianness auto-detection
 
 /*
@@ -58,7 +58,7 @@
     ARM is bi-endian, detect using __ARMEL__ or __ARMEB__, falling back to
     auto-detection implemented below.
 */
-#if defined(__arm__) || defined(__TARGET_ARCH_ARM) || defined(_M_ARM) || defined(_M_ARM64) || defined(__aarch64__) || defined(__ARM64__)
+#elif defined(__arm__) || defined(__TARGET_ARCH_ARM) || defined(_M_ARM) || defined(_M_ARM64) || defined(__aarch64__) || defined(__ARM64__)
 #  if defined(__aarch64__) || defined(__ARM64__) || defined(_M_ARM64)
 #    define Q_PROCESSOR_ARM_64
 #    define Q_PROCESSOR_WORDSIZE 8
