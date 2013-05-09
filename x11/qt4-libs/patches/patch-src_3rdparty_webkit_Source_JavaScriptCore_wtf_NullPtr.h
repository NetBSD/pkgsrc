$NetBSD: patch-src_3rdparty_webkit_Source_JavaScriptCore_wtf_NullPtr.h,v 1.1 2013/05/09 14:07:08 joerg Exp $

--- src/3rdparty/webkit/Source/JavaScriptCore/wtf/NullPtr.h.orig	2013-04-29 18:43:12.000000000 +0000
+++ src/3rdparty/webkit/Source/JavaScriptCore/wtf/NullPtr.h
@@ -35,7 +35,7 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
     #define __has_feature(feature) 0
 #endif
 
-#if __has_feature(cxx_nullptr) || (GCC_VERSION_AT_LEAST(4, 6, 0) && defined(__GXX_EXPERIMENTAL_CXX0X__)) || (defined(_MSC_VER) && _MSC_VER >= 1600 && !COMPILER(INTEL))
+#if __has_feature(cxx_nullptr) || (GCC_VERSION_AT_LEAST(4, 6, 0) && defined(__GXX_EXPERIMENTAL_CXX0X__)) || (defined(_MSC_VER) && _MSC_VER >= 1600 && !COMPILER(INTEL)) || defined(_LIBCPP_VERSION)
 
 #define HAVE_NULLPTR 1
 
