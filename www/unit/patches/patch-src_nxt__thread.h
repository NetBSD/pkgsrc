$NetBSD: patch-src_nxt__thread.h,v 1.1 2021/08/22 05:10:19 gutteridge Exp $

SunOS defines PTHREAD_STACK_MIN as a function call.

--- src/nxt_thread.h.orig	1970-01-01 00:00:00.000000000 +0000
+++ src/nxt_thread.h
@@ -142,7 +142,7 @@ nxt_thread_yield()
 #endif
 
 
-#if (PTHREAD_STACK_MIN)
+#ifdef PTHREAD_STACK_MIN
 #define NXT_THREAD_STACK_MIN  PTHREAD_STACK_MIN
 
 #else
