$NetBSD: patch-Source_WTF_wtf_PlatformHave.h,v 1.4 2022/05/31 12:52:14 leot Exp $

Add support for NetBSD.

Shared upstream via <https://bugs.webkit.org/show_bug.cgi?id=241125>

--- Source/WTF/wtf/PlatformHave.h.orig	2022-02-23 08:58:57.000000000 +0000
+++ Source/WTF/wtf/PlatformHave.h
@@ -229,7 +229,7 @@
 #define HAVE_HOSTED_CORE_ANIMATION 1
 #endif
 
-#if OS(DARWIN) || OS(FUCHSIA) || ((OS(FREEBSD) || OS(OPENBSD) || OS(LINUX)) && (CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(MIPS) || CPU(RISCV64)))
+#if OS(DARWIN) || OS(FUCHSIA) || ((OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD) || OS(LINUX)) && (CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(MIPS) || CPU(RISCV64)))
 #define HAVE_MACHINE_CONTEXT 1
 #endif
 
