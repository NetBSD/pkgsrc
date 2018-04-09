$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.9 2018/04/09 08:33:48 wiz Exp $

Add support for sparc64:

 <https://bugs.webkit.org/show_bug.cgi?id=129963>

From OpenBSD ports.

--- Source/WTF/wtf/Platform.h.orig	2017-10-16 12:18:56.000000000 +0000
+++ Source/WTF/wtf/Platform.h
@@ -155,6 +155,12 @@
 #define WTF_CPU_BIG_ENDIAN 1
 #endif
 
+/* CPU(SPARC64) - SPARC V9 */
+#if defined(__sparc64__)
+#define WTF_CPU_SPARC64 1
+#define WTF_CPU_BIG_ENDIAN 1
+#endif
+
 /* CPU(X86) - i386 / x86 32-bit */
 #if   defined(__i386__) \
     || defined(i386)     \
@@ -353,7 +359,7 @@
 
 #endif /* ARM */
 
-#if CPU(ARM) || CPU(MIPS) || CPU(SH4) || CPU(ALPHA) || CPU(HPPA)
+#if CPU(ARM) || CPU(MIPS) || CPU(SH4) || CPU(ALPHA) || CPU(HPPA) || CPU(SPARC64)
 #define WTF_CPU_NEEDS_ALIGNED_ACCESS 1
 #endif
 
@@ -713,7 +719,8 @@
     || CPU(S390X) \
     || CPU(MIPS64) \
     || CPU(PPC64) \
-    || CPU(PPC64LE)
+    || CPU(PPC64LE) \
+    || CPU(SPARC64)
 #define USE_JSVALUE64 1
 #else
 #define USE_JSVALUE32_64 1
@@ -770,7 +777,7 @@
 
 #if !defined(ENABLE_DFG_JIT) && ENABLE(JIT)
 /* Enable the DFG JIT on X86 and X86_64. */
-#if (CPU(X86) || CPU(X86_64)) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(WINDOWS) || OS(HURD))
+#if (CPU(X86) || CPU(X86_64)) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD) || OS(WINDOWS) || OS(HURD))
 #define ENABLE_DFG_JIT 1
 #endif
 /* Enable the DFG JIT on ARMv7.  Only tested on iOS and Qt/GTK+ Linux. */
