$NetBSD: patch-gfx-ycbcr-chromium_types.h,v 1.1 2022/05/28 18:31:13 martin Exp $

Add preprocessor defines used by gcc/clang on NetBSD for powerpc.

--- gfx/ycbcr/chromium_types.h.orig	2017-04-11 04:13:08.000000000 +0200
+++ gfx/ycbcr/chromium_types.h	2022-05-27 16:59:08.068703784 +0200
@@ -27,7 +27,7 @@
 #define ARCH_CPU_ARM_FAMILY 1
 #define ARCH_CPU_ARMEL 1
 #define ARCH_CPU_32_BITS 1
-#elif defined(__ppc__) || defined(__powerpc) || defined(__PPC__)
+#elif defined(__ppc__) || defined(__powerpc) || defined(__powerpc__) || defined(__PPC__)
 #define ARCH_CPU_PPC_FAMILY 1
 #define ARCH_CPU_PPC 1
 #define ARCH_CPU_32_BITS 1
