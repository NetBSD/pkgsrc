$NetBSD: patch-src_compiler.h,v 1.2 2019/09/17 11:43:29 tnn Exp $

Fix build for NetBSD

--- src/compiler.h.orig	2019-08-18 21:40:33.000000000 +0000
+++ src/compiler.h
@@ -94,6 +94,7 @@
 # define unreachable do {} while(0)
 #endif
 
+#ifndef __NetBSD__
 #ifndef __STDC_NO_THREADS__
 # include <threads.h>
 #elif __STDC_VERSION__ >= 201112L
@@ -103,6 +104,9 @@
 #else
 # define thread_local _Pragma("GCC error \"No thread local storage support\"") __error__
 #endif
+#else
+# define thread_local __thread
+#endif
 
 typedef unsigned long ulong;
 typedef unsigned int uint;
