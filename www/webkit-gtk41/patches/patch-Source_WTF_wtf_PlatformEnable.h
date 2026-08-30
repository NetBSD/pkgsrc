$NetBSD: patch-Source_WTF_wtf_PlatformEnable.h,v 1.1 2026/08/30 14:25:05 wiz Exp $

--- Source/WTF/wtf/PlatformEnable.h.orig	2025-02-25 08:25:40.559371500 +0000
+++ Source/WTF/wtf/PlatformEnable.h
@@ -696,7 +696,7 @@
 #if !defined(ENABLE_DFG_JIT) && ENABLE(JIT)
 
 /* Enable the DFG JIT on X86 and X86_64. */
-#if CPU(X86_64) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(HAIKU) || OS(HURD) || OS(WINDOWS))
+#if CPU(X86_64) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(HAIKU) || OS(HURD) || OS(WINDOWS))
 #define ENABLE_DFG_JIT 1
 #endif
 
