$NetBSD: patch-Source_WTF_wtf_TypeTraits.h,v 1.1 2017/04/26 10:27:43 wiz Exp $

Fix build with icu-59.
https://bugreports.qt.io/browse/QTBUG-35971

--- Source/WTF/wtf/TypeTraits.h.orig	2015-10-13 04:37:08.000000000 +0000
+++ Source/WTF/wtf/TypeTraits.h
@@ -75,6 +75,10 @@ namespace WTF {
 #if !COMPILER(MSVC) || defined(_NATIVE_WCHAR_T_DEFINED)
     template<> struct IsInteger<wchar_t>            { static const bool value = true; };
 #endif
+#if COMPILER_SUPPORTS(CXX_NEW_CHAR_TYPES)
+    template<> struct IsInteger<char16_t>           { static const bool value = true; };
+    template<> struct IsInteger<char32_t>           { static const bool value = true; };
+#endif
 
     template<typename T> struct IsFloatingPoint     { static const bool value = false; };
     template<> struct IsFloatingPoint<float>        { static const bool value = true; };
