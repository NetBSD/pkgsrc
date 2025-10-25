$NetBSD: patch-Source_WTF_wtf_InlineASM.h,v 1.1 2025/10/25 15:00:45 tsutsui Exp $

Add support for NetBSD, OpenBSD and Solaris.

--- Source/WTF/wtf/InlineASM.h.orig	2022-06-30 09:49:30.096184300 +0000
+++ Source/WTF/wtf/InlineASM.h
@@ -43,7 +43,7 @@
 #define THUMB_FUNC_PARAM(name)
 #endif
 
-#if (OS(LINUX) || OS(FREEBSD)) && CPU(X86_64)
+#if ((OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD) || OS(SOLARIS)) && CPU(X86_64)) || (OS(SOLARIS) && CPU(X86)) 
 #define GLOBAL_REFERENCE(name) #name "@plt"
 #elif CPU(X86) && COMPILER(MINGW)
 #define GLOBAL_REFERENCE(name) "@" #name "@4"
