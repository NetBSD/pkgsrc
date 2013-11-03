$NetBSD: patch-xpcom_string_public_nsAlgorithm.h,v 1.1 2013/11/03 04:52:00 ryoon Exp $

--- xpcom/string/public/nsAlgorithm.h.orig	2013-05-11 19:19:56.000000000 +0000
+++ xpcom/string/public/nsAlgorithm.h
@@ -45,7 +45,10 @@ XPCOM_MAX( const T& a, const T& b )
     return a > b ? a : b;
   }
 
-#if defined(_MSC_VER) && (_MSC_VER < 1600)
+#if (defined(_MSC_VER) && (_MSC_VER < 1600)) || \
+    ((defined(__GLIBCXX__) && __GLIBCXX__ < 20121005) && \
+     (defined(_GLIBCXX_USE_LONG_LONG) && \
+      (!_GLIBCXX_USE_C99 || _GLIBCXX_USE_C99_LONG_LONG_DYNAMIC)))
 namespace std {
 inline
 long long
