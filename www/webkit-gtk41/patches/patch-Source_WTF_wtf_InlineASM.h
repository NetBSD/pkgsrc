$NetBSD: patch-Source_WTF_wtf_InlineASM.h,v 1.1 2026/08/30 14:25:05 wiz Exp $

--- Source/WTF/wtf/InlineASM.h.orig	2025-02-25 08:25:40.551371300 +0000
+++ Source/WTF/wtf/InlineASM.h
@@ -43,7 +43,7 @@
 #define THUMB_FUNC_PARAM(name)
 #endif
 
-#if (OS(LINUX) || OS(FREEBSD) || OS(HAIKU) || OS(QNX)) && CPU(X86_64)
+#if (OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(HAIKU) || OS(QNX)) && CPU(X86_64)
 #define GLOBAL_REFERENCE(name) #name "@plt"
 #elif OS(LINUX) && CPU(X86) && defined(__PIC__)
 #define GLOBAL_REFERENCE(name) SYMBOL_STRING(name) "@plt"
