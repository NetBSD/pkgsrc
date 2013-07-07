$NetBSD: patch-src_3rdparty_webkit_Source_JavaScriptCore_wtf_NullPtr.h,v 1.2 2013/07/07 18:13:56 adam Exp $

--- src/3rdparty/webkit/Source/JavaScriptCore/wtf/NullPtr.h.orig	2013-06-07 05:16:54.000000000 +0000
+++ src/3rdparty/webkit/Source/JavaScriptCore/wtf/NullPtr.h
@@ -35,8 +35,14 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
     #define __has_feature(feature) 0
 #endif
 
-#if __has_feature(cxx_nullptr) || (GCC_VERSION_AT_LEAST(4, 6, 0) && defined(__GXX_EXPERIMENTAL_CXX0X__)) || (defined(_MSC_VER) && _MSC_VER >= 1600 && !COMPILER(INTEL))
+#if __has_feature(cxx_nullptr) || (GCC_VERSION_AT_LEAST(4, 6, 0) && defined(__GXX_EXPERIMENTAL_CXX0X__)) || (defined(_MSC_VER) && _MSC_VER >= 1600 && !COMPILER(INTEL)) || defined(_LIBCPP_VERSION)
 
+#if defined(__clang__) && !defined(_LIBCPP_VERSION)
+namespace std
+{
+    typedef decltype(nullptr) nullptr_t;
+}
+#endif
 #define HAVE_NULLPTR 1
 
 #else
