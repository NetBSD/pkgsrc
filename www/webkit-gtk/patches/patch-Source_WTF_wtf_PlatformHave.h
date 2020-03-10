$NetBSD: patch-Source_WTF_wtf_PlatformHave.h,v 1.1 2020/03/10 18:14:04 leot Exp $

Add support for NetBSD.

--- Source/WTF/wtf/PlatformHave.h.orig	2020-02-26 10:34:01.000000000 +0000
+++ Source/WTF/wtf/PlatformHave.h
@@ -222,7 +222,7 @@
 #define HAVE_HOSTED_CORE_ANIMATION 1
 #endif
 
-#if OS(DARWIN) || OS(FUCHSIA) || ((OS(FREEBSD) || defined(__GLIBC__) || defined(__BIONIC__)) && (CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(MIPS)))
+#if OS(DARWIN) || OS(FUCHSIA) || ((OS(FREEBSD) || OS(NETBSD) || defined(__GLIBC__) || defined(__BIONIC__)) && (CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(MIPS)))
 #define HAVE_MACHINE_CONTEXT 1
 #endif
 
