$NetBSD: patch-mozilla_mfbt_Atomics.h,v 1.1 2013/09/28 14:37:05 ryoon Exp $

--- mozilla/mfbt/Atomics.h.orig	2013-09-16 18:26:51.000000000 +0000
+++ mozilla/mfbt/Atomics.h
@@ -37,7 +37,7 @@
     */
 #  if !defined(__linux__) && !defined(__OpenBSD__) && \
       (__cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)) && \
-      __has_include(<atomic>)
+      __has_include_next(<atomic>)
 #    define MOZ_HAVE_CXX11_ATOMICS
 #  endif
 /*
