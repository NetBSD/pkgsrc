$NetBSD: patch-kjs_wtf_HashTable.h,v 1.1 2013/05/06 15:03:19 joerg Exp $

--- kjs/wtf/HashTable.h.orig	2013-05-03 23:46:27.000000000 +0000
+++ kjs/wtf/HashTable.h
@@ -245,7 +245,7 @@ namespace WTF {
 
     using std::swap;
 
-#if !COMPILER(MSVC)
+#if !COMPILER(MSVC) && !defined(_LIBCPP_VERSION)
     // Visual C++ has a swap for pairs defined.
 
     // swap pairs by component, in case of pair members that specialize swap
