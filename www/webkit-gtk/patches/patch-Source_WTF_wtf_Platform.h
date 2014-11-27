$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.3 2014/11/27 13:47:03 jmcneill Exp $

--- Source/WTF/wtf/Platform.h.orig	2014-10-22 08:16:09.000000000 +0000
+++ Source/WTF/wtf/Platform.h
@@ -632,6 +632,11 @@
 #define USE_SYSTEM_MALLOC 1
 #endif
 
+/* Workaround an alignment issue with fastMalloc on NetBSD/arm */
+#if OS(NETBSD) && CPU(ARM)
+#define USE_SYSTEM_MALLOC 1
+#endif
+
 #if !defined(ENABLE_GLOBAL_FASTMALLOC_NEW)
 #define ENABLE_GLOBAL_FASTMALLOC_NEW 1
 #endif
@@ -723,7 +728,7 @@
    low-level interpreter. */
 #if !defined(ENABLE_LLINT) \
     && ENABLE(JIT) \
-    && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD)) \
+    && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD)) \
     && (PLATFORM(MAC) || PLATFORM(IOS) || PLATFORM(GTK)) \
     && (CPU(X86) || CPU(X86_64) || CPU(ARM_THUMB2) || CPU(ARM_TRADITIONAL) || CPU(ARM64) || CPU(MIPS) || CPU(SH4))
 #define ENABLE_LLINT 1
