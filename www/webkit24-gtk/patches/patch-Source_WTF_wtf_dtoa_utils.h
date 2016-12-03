$NetBSD: patch-Source_WTF_wtf_dtoa_utils.h,v 1.1 2016/12/03 16:30:05 martin Exp $

Add support for sparc and sparc64

--- Source/WTF/wtf/dtoa/utils.h.orig	2016-04-10 08:48:36.000000000 +0200
+++ Source/WTF/wtf/dtoa/utils.h	2016-12-01 17:15:30.400636439 +0100
@@ -49,7 +49,7 @@
 defined(__ARMEL__) || \
 defined(_MIPS_ARCH_MIPS32R2)
 #define DOUBLE_CONVERSION_CORRECT_DOUBLE_OPERATIONS 1
-#elif CPU(MIPS) || CPU(MIPS64) || CPU(PPC) || CPU(PPC64) || CPU(PPC64LE) || OS(WINCE) || CPU(SH4) || CPU(S390) || CPU(S390X) || CPU(IA64) || CPU(ALPHA) || CPU(ARM64) || CPU(HPPA)
+#elif CPU(MIPS) || CPU(MIPS64) || CPU(PPC) || CPU(PPC64) || CPU(PPC64LE) || OS(WINCE) || CPU(SH4) || CPU(S390) || CPU(S390X) || CPU(IA64) || CPU(ALPHA) || CPU(ARM64) || CPU(HPPA) || CPU(SPARC) || CPU(SPARC64)
 #define DOUBLE_CONVERSION_CORRECT_DOUBLE_OPERATIONS 1
 #elif defined(_M_IX86) || defined(__i386__)
 #if defined(_WIN32)
