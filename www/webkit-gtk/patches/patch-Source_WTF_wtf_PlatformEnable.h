$NetBSD: patch-Source_WTF_wtf_PlatformEnable.h,v 1.1 2020/03/10 18:14:04 leot Exp $

Enable the JIT on NetBSD.

--- Source/WTF/wtf/PlatformEnable.h.orig	2020-02-04 10:24:07.000000000 +0000
+++ Source/WTF/wtf/PlatformEnable.h
@@ -625,12 +625,12 @@
 #if !defined(ENABLE_DFG_JIT) && ENABLE(JIT)
 
 /* Enable the DFG JIT on X86 and X86_64. */
-#if CPU(X86_64) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(HURD) || OS(WINDOWS))
+#if CPU(X86_64) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(HURD) || OS(WINDOWS))
 #define ENABLE_DFG_JIT 1
 #endif
 
-/* Enable the DFG JIT on ARMv7.  Only tested on iOS, Linux, and FreeBSD. */
-#if (CPU(ARM_THUMB2) || CPU(ARM64)) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD))
+/* Enable the DFG JIT on ARMv7.  Only tested on iOS, Linux, and FreeBSD and NetBSD. */
+#if (CPU(ARM_THUMB2) || CPU(ARM64)) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD))
 #define ENABLE_DFG_JIT 1
 #endif
 
