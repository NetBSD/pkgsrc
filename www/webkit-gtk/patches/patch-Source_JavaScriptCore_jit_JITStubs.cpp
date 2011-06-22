$NetBSD: patch-Source_JavaScriptCore_jit_JITStubs.cpp,v 1.1 2011/06/22 14:05:37 wiz Exp $

Fix build on NetBSD-5.99.53/amd64.

--- Source/JavaScriptCore/jit/JITStubs.cpp.orig	2011-03-21 18:41:54.000000000 +0000
+++ Source/JavaScriptCore/jit/JITStubs.cpp
@@ -79,7 +79,7 @@ namespace JSC {
 #define THUMB_FUNC_PARAM(name)
 #endif
 
-#if (OS(LINUX) || OS(FREEBSD)) && CPU(X86_64)
+#if (OS(LINUX) || OS(FREEBSD) || OS(NETBSD)) && CPU(X86_64)
 #define SYMBOL_STRING_RELOCATION(name) #name "@plt"
 #elif OS(DARWIN)
 #define SYMBOL_STRING_RELOCATION(name) "_" #name
