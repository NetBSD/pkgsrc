$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.3 2017/04/24 15:40:12 wiz Exp $

Add support for sparc and sparc64, disable ASSEMBLER and YARR_JIT for now

--- Source/WTF/wtf/Platform.h.orig	2016-04-10 06:48:36.000000000 +0000
+++ Source/WTF/wtf/Platform.h
@@ -153,6 +153,18 @@
 #define WTF_CPU_BIG_ENDIAN 1
 #endif
 
+/* CPU(SPARC) - SPARC 32-bit */
+#if defined(__sparc__) && !defined(_LP64)
+#define WTF_CPU_SPARC 1
+#define WTF_CPU_BIG_ENDIAN 1
+#endif
+
+/* CPU(SPARC64) - SPARC 64-bit */
+#if defined(__sparc__) && defined(_LP64)
+#define WTF_CPU_SPARC64 1
+#define WTF_CPU_BIG_ENDIAN 1
+#endif
+
 /* CPU(X86) - i386 / x86 32-bit */
 #if   defined(__i386__) \
     || defined(i386)     \
@@ -656,6 +668,7 @@
     || CPU(ALPHA) \
     || CPU(ARM64) \
     || CPU(S390X) \
+    || CPU(SPARC64) \
     || CPU(MIPS64) \
     || CPU(PPC64) \
     || CPU(PPC64LE)
@@ -824,7 +837,7 @@
 #define ENABLE_REGEXP_TRACING 0
 
 /* Yet Another Regex Runtime - turned on by default for JIT enabled ports. */
-#if !defined(ENABLE_YARR_JIT) && (ENABLE(JIT) || ENABLE(LLINT_C_LOOP))
+#if !defined(ENABLE_YARR_JIT) && (ENABLE(JIT) || ENABLE(LLINT_C_LOOP)) && !CPU(SPARC64) && !CPU(SPARC)
 #define ENABLE_YARR_JIT 1
 
 /* Setting this flag compares JIT results with interpreter results. */
@@ -837,10 +850,12 @@
 #if defined(ENABLE_ASSEMBLER) && !ENABLE_ASSEMBLER
 #error "Cannot enable the JIT or RegExp JIT without enabling the Assembler"
 #else
+#if !CPU(SPARC) && !CPU(SPARC64)
 #undef ENABLE_ASSEMBLER
 #define ENABLE_ASSEMBLER 1
 #endif
 #endif
+#endif
 
 /* If the Disassembler is enabled, then the Assembler must be enabled as well: */
 #if ENABLE(DISASSEMBLER)
