$NetBSD: patch-Source_WTF_wtf_Compiler.h,v 1.1 2017/04/26 10:27:43 wiz Exp $

Fix build with icu-59.
https://bugreports.qt.io/browse/QTBUG-35971

--- Source/WTF/wtf/Compiler.h.orig	2015-10-13 04:37:08.000000000 +0000
+++ Source/WTF/wtf/Compiler.h
@@ -61,6 +61,7 @@
 #define WTF_COMPILER_SUPPORTS_HAS_TRIVIAL_DESTRUCTOR __has_feature(has_trivial_destructor)
 #define WTF_COMPILER_SUPPORTS_CXX_STRONG_ENUMS __has_feature(cxx_strong_enums)
 #define WTF_COMPILER_SUPPORTS_CXX_REFERENCE_QUALIFIED_FUNCTIONS __has_feature(cxx_reference_qualified_functions)
+#define WTF_COMPILER_SUPPORTS_CXX_NEW_CHAR_TYPES !defined(_LIBCPP_HAS_NO_UNICODE_CHARS)
 
 #endif
 
@@ -142,6 +143,7 @@
 #define WTF_COMPILER_SUPPORTS_CXX_DELETED_FUNCTIONS 1
 #endif
 #if GCC_VERSION_AT_LEAST(4, 5, 0)
+#define WTF_COMPILER_SUPPORTS_CXX_NEW_CHAR_TYPES 1
 #define WTF_COMPILER_SUPPORTS_CXX_EXPLICIT_CONVERSIONS 1
 #endif
 #if GCC_VERSION_AT_LEAST(4, 6, 0)
