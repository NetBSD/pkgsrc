$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_wtf_HashTable.h,v 1.2 2013/07/07 18:13:56 adam Exp $

--- src/3rdparty/javascriptcore/JavaScriptCore/wtf/HashTable.h.orig	2013-04-29 18:21:34.000000000 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/wtf/HashTable.h
@@ -257,7 +257,7 @@ namespace WTF {
 
     using std::swap;
 
-#if !COMPILER(MSVC) && !OS(QNX)
+#if !COMPILER(MSVC) && !OS(QNX) && !defined(_LIBCPP_VERSION) && !defined(__GXX_EXPERIMENTAL_CXX0X__)
     // The Dinkumware C++ library (used by MSVC and QNX) has a swap for pairs defined.
 
     // swap pairs by component, in case of pair members that specialize swap
