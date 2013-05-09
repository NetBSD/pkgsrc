$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_wtf_Threading.h,v 1.1 2013/05/09 14:07:08 joerg Exp $

--- src/3rdparty/javascriptcore/JavaScriptCore/wtf/Threading.h.orig	2013-04-29 18:12:16.000000000 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/wtf/Threading.h
@@ -78,7 +78,9 @@
 #elif OS(QNX)
 #include <atomic.h>
 #elif COMPILER(GCC) && !OS(SYMBIAN)
-#if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))
+#include <ciso646>
+#ifdef _LIBCPP_VERSION
+#elif (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))
 #include <ext/atomicity.h>
 #else
 #include <bits/atomicity.h>
@@ -250,8 +252,13 @@ inline int atomicDecrement(int volatile*
 #elif COMPILER(GCC) && !CPU(SPARC64) && !OS(SYMBIAN) // sizeof(_Atomic_word) != sizeof(int) on sparc64 gcc
 #define WTF_USE_LOCKFREE_THREADSAFESHARED 1
 
+#ifdef _LIBCPP_VERSION
+inline int atomicIncrement(int volatile* addend) { return __sync_fetch_and_add(addend, 1) + 1; }
+inline int atomicDecrement(int volatile* addend) { return __sync_fetch_and_add(addend, -1) - 1; }
+#else
 inline int atomicIncrement(int volatile* addend) { return __gnu_cxx::__exchange_and_add(addend, 1) + 1; }
 inline int atomicDecrement(int volatile* addend) { return __gnu_cxx::__exchange_and_add(addend, -1) - 1; }
+#endif
 
 #endif
 
