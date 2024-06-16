$NetBSD: patch-src_3rdparty_mapbox-gl-native_deps_rapidjson_1.1.0_include_rapidjson_document.h,v 1.1 2024/06/16 11:33:39 markd Exp $

https://github.com/Tencent/rapidjson/commit/3b2441b8.patch
fix build with gcc14

--- src/3rdparty/mapbox-gl-native/deps/rapidjson/1.1.0/include/rapidjson/document.h.orig	2024-05-08 05:14:45.000000000 +0000
+++ src/3rdparty/mapbox-gl-native/deps/rapidjson/1.1.0/include/rapidjson/document.h
@@ -316,8 +316,6 @@ struct GenericStringRef {
 
     GenericStringRef(const GenericStringRef& rhs) : s(rhs.s), length(rhs.length) {}
 
-    GenericStringRef& operator=(const GenericStringRef& rhs) { s = rhs.s; length = rhs.length; }
-
     //! implicit conversion to plain CharType pointer
     operator const Ch *() const { return s; }
 
