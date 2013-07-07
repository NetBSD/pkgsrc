$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_wtf_TypeTraits.h,v 1.1 2013/07/07 18:13:56 adam Exp $

--- src/3rdparty/javascriptcore/JavaScriptCore/wtf/TypeTraits.h.orig	2013-06-07 05:16:58.000000000 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/wtf/TypeTraits.h
@@ -25,7 +25,7 @@
 #include "Platform.h"
 
 #if (defined(__GLIBCXX__) && (__GLIBCXX__ >= 20070724) && defined(__GXX_EXPERIMENTAL_CXX0X__)) || (defined(_MSC_VER) && (_MSC_VER >= 1600))
-#include <type_traits>
+#include <tr1/type_traits>
 #endif
 
 namespace WTF {
