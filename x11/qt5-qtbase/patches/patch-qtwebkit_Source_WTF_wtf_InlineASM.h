$NetBSD: patch-qtwebkit_Source_WTF_wtf_InlineASM.h,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add NetBSD support
* Add Solaris/SunOS support

--- qtwebkit/Source/WTF/wtf/InlineASM.h.orig	2013-11-27 01:01:21.000000000 +0000
+++ qtwebkit/Source/WTF/wtf/InlineASM.h
@@ -42,7 +42,7 @@
 #define THUMB_FUNC_PARAM(name)
 #endif
 
-#if (OS(LINUX) || OS(FREEBSD)) && CPU(X86_64)
+#if (OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(SOLARIS)) && CPU(X86_64) || (OS(SOLARIS) && CPU(X86))
 #define GLOBAL_REFERENCE(name) #name "@plt"
 #elif CPU(X86) && COMPILER(MINGW)
 #define GLOBAL_REFERENCE(name) "@" #name "@4"
