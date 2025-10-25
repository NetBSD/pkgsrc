$NetBSD: patch-Source_JavaScriptCore_API_glib_JSCOptions.cpp,v 1.1 2025/10/25 14:45:27 tsutsui Exp $

- fix build errors on NetBSD/arm where size_t == unsigned long

--- Source/JavaScriptCore/API/glib/JSCOptions.cpp.orig	2022-06-30 09:49:25.102854500 +0000
+++ Source/JavaScriptCore/API/glib/JSCOptions.cpp
@@ -73,7 +73,8 @@ static void valueToGValue(int32_t value,
     g_value_set_int(gValue, value);
 }
 
-#if CPU(ADDRESS64)
+#if CPU(ADDRESS64) || OS(DARWIN) || \
+  (defined(__NetBSD__) && (defined(__arm__) || defined(__powerpc__)))
 static bool valueFromGValue(const GValue* gValue, unsigned& value)
 {
     value = g_value_get_uint(gValue);
@@ -542,7 +543,8 @@ static JSCOptionType jscOptionsType(int)
     return JSC_OPTION_INT;
 }
 
-#if CPU(ADDRESS64)
+#if CPU(ADDRESS64) || OS(DARWIN) || \
+  (defined(__NetBSD__) && (defined(__arm__) || defined(__powerpc__)))
 static JSCOptionType jscOptionsType(unsigned)
 {
     return JSC_OPTION_UINT;
