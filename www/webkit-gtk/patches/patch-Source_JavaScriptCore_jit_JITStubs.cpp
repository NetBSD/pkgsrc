$NetBSD: patch-Source_JavaScriptCore_jit_JITStubs.cpp,v 1.2 2011/10/07 12:17:25 drochner Exp $

Fix build on NetBSD-5.99.53/amd64.

--- Source/JavaScriptCore/jit/JITStubs.cpp.orig	2011-09-26 20:54:57.000000000 +0000
+++ Source/JavaScriptCore/jit/JITStubs.cpp
@@ -80,7 +80,7 @@ namespace JSC {
 #define THUMB_FUNC_PARAM(name)
 #endif
 
-#if (OS(LINUX) || OS(FREEBSD)) && CPU(X86_64)
+#if (OS(LINUX) || OS(FREEBSD) || OS(NETBSD)) && CPU(X86_64)
 #define SYMBOL_STRING_RELOCATION(name) #name "@plt"
 #elif OS(DARWIN) || (CPU(X86_64) && COMPILER(MINGW) && !GCC_VERSION_AT_LEAST(4, 5, 0))
 #define SYMBOL_STRING_RELOCATION(name) "_" #name
