$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.4 2018/08/16 11:49:13 he Exp $

Add support for sparc and sparc64, disable ASSEMBLER for now.
Turn off YARR_JIT if JIT is turned off.

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
@@ -668,6 +681,7 @@
 /* Disable the JITs if we're forcing the cloop to be enabled */
 #if defined(ENABLE_LLINT_C_LOOP) && ENABLE_LLINT_C_LOOP
 #define ENABLE_JIT 0
+#define ENABLE_YARR_JIT 0
 #define ENABLE_DFG_JIT 0
 #define ENABLE_FTL_JIT 0
 #endif
@@ -757,9 +771,11 @@
 /* If the jit is not available, enable the LLInt C Loop: */
 #if !ENABLE(JIT)
 #undef ENABLE_LLINT        /* Undef so that we can redefine it. */
+#undef ENABLE_YARR_JIT     /* Undef so that we can redefine it. */
 #undef ENABLE_LLINT_C_LOOP /* Undef so that we can redefine it. */
 #undef ENABLE_DFG_JIT      /* Undef so that we can redefine it. */
 #define ENABLE_LLINT 1
+#define ENABLE_YARR_JIT 0
 #define ENABLE_LLINT_C_LOOP 1
 #define ENABLE_DFG_JIT 0
 #endif
