$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_wtf_HashTable.h,v 1.4 2018/01/17 18:37:34 markd Exp $

--- src/3rdparty/javascriptcore/JavaScriptCore/wtf/HashTable.h.orig	2015-05-07 14:14:48.000000000 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/wtf/HashTable.h
@@ -257,7 +257,8 @@ namespace WTF {
 
     using std::swap;
 
-#if !COMPILER(MSVC) && !OS(QNX) && !defined(_LIBCPP_VERSION)
+#if 0 
+    !COMPILER(MSVC) && !OS(QNX) && !defined(_LIBCPP_VERSION)
     // The Dinkumware C++ library (used by MSVC and QNX) and clang's libc++ have a swap for pairs defined.
 
     // swap pairs by component, in case of pair members that specialize swap
