$NetBSD: patch-Source_WTF_wtf_Compiler.h,v 1.1 2013/05/12 06:11:17 richard Exp $

--- Source/WTF/wtf/Compiler.h.orig	2012-11-23 20:12:16.000000000 +0000
+++ Source/WTF/wtf/Compiler.h
@@ -122,7 +122,7 @@
 
 /* Specific compiler features */
 #if COMPILER(GCC) && !COMPILER(CLANG)
-#if GCC_VERSION_AT_LEAST(4, 7, 0) && __cplusplus >= 201103L
+#if GCC_VERSION_AT_LEAST(4, 7, 0) && defined(__cplusplus) && __cplusplus >= 201103L
 #define WTF_COMPILER_SUPPORTS_CXX_RVALUE_REFERENCES 1
 #define WTF_COMPILER_SUPPORTS_CXX_DELETED_FUNCTIONS 1
 #define WTF_COMPILER_SUPPORTS_CXX_NULLPTR 1
