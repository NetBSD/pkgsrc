$NetBSD: patch-src_3rdparty_webkit_Source_JavaScriptCore_wtf_Atomics.h,v 1.2 2013/07/07 18:13:56 adam Exp $

--- src/3rdparty/webkit/Source/JavaScriptCore/wtf/Atomics.h.orig	2013-06-07 05:16:54.000000000 +0000
+++ src/3rdparty/webkit/Source/JavaScriptCore/wtf/Atomics.h
@@ -69,6 +69,8 @@
 #include <cutils/atomic.h>
 #elif OS(QNX)
 #include <atomic.h>
+#elif __cplusplus >= 201103L
+#include <atomic>
 #elif COMPILER(GCC) && !OS(SYMBIAN)
 #if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))
 #include <ext/atomicity.h>
@@ -106,6 +108,11 @@ inline int atomicDecrement(int volatile*
 inline int atomicIncrement(int volatile* addend) { return (int) atomic_add_value((unsigned int volatile*)addend, 1); }
 inline int atomicDecrement(int volatile* addend) { return (int) atomic_sub_value((unsigned int volatile*)addend, 1); }
 
+#elif __cplusplus >= 201103L
+#define WTF_USE_LOCKFREE_THREADSAFEREFCOUNTED 1
+inline int atomicIncrement(std::atomic<int> * addend) { return *addend++; }
+inline int atomicDecrement(std::atomic<int> * addend) { return *addend--; }
+
 #elif COMPILER(GCC) && !CPU(SPARC64) && !OS(SYMBIAN) // sizeof(_Atomic_word) != sizeof(int) on sparc64 gcc
 #define WTF_USE_LOCKFREE_THREADSAFEREFCOUNTED 1
 
@@ -114,9 +121,15 @@ inline int atomicDecrement(int volatile*
 
 #endif
 
+#if !OS(DARWIN) && __cplusplus >= 201103L
+typedef std::atomic<int> atomic_int;
+#else
+typedef int volatile atomic_int;
+#endif
 } // namespace WTF
 
 #if USE(LOCKFREE_THREADSAFEREFCOUNTED)
+using WTF::atomic_int;
 using WTF::atomicDecrement;
 using WTF::atomicIncrement;
 #endif
