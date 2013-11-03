$NetBSD: patch-mfbt_Atomics.h,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- mfbt/Atomics.h.orig	2013-09-10 03:43:48.000000000 +0000
+++ mfbt/Atomics.h
@@ -37,7 +37,7 @@
     */
 #  if !defined(__linux__) && !defined(__OpenBSD__) && \
       (__cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)) && \
-      __has_include(<atomic>)
+      __has_include_next(<atomic>)
 #    define MOZ_HAVE_CXX11_ATOMICS
 #  endif
 /*
