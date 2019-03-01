$NetBSD: patch-src_compiler.h,v 1.1 2019/03/01 17:13:32 youri Exp $

Fix build for NetBSD

--- src/compiler.h.orig	2019-02-06 21:29:32.000000000 +0000
+++ src/compiler.h
@@ -2,7 +2,9 @@
 // Copyright (c) 2018 Yuxuan Shui <yshuiv7@gmail.com>
 #pragma once
 
+#ifndef __NetBSD__
 #include <stdc-predef.h>
+#endif
 
 #define auto         __auto_type
 #define likely(x)    __builtin_expect(!!(x), 1)
@@ -82,6 +84,7 @@
 # define unreachable do {} while(0)
 #endif
 
+#ifndef __NetBSD__
 #ifndef __STDC_NO_THREADS__
 # include <threads.h>
 #elif __STDC_VERSION__ >= 201112L
@@ -91,3 +94,6 @@
 #else
 # define thread_local _Pragma("GCC error \"No thread local storage support\"") __error__
 #endif
+#else
+# define thread_local __thread
+#endif
