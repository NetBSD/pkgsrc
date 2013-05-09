$NetBSD: patch-Source_WTF_wtf_Atomics.h,v 1.1 2013/05/09 14:04:42 joerg Exp $

--- Source/WTF/wtf/Atomics.h.orig	2012-11-23 20:12:16.000000000 +0000
+++ Source/WTF/wtf/Atomics.h
@@ -72,7 +72,10 @@
 #elif OS(ANDROID)
 #include <sys/atomics.h>
 #elif COMPILER(GCC)
-#if ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))) && !defined(__LSB_VERSION__)
+#include <ciso646>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <atomic>
+#elif ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))) && !defined(__LSB_VERSION__)
 #include <ext/atomicity.h>
 #else
 #include <bits/atomicity.h>
@@ -112,6 +115,11 @@ inline int atomicDecrement(int volatile*
 inline int atomicIncrement(int volatile* addend) { return __atomic_inc(addend) + 1; }
 inline int atomicDecrement(int volatile* addend) { return __atomic_dec(addend) - 1; }
 
+#elif defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#define WTF_USE_LOCKFREE_THREADSAFEREFCOUNTED 1
+inline int atomicIncrement(std::atomic<int> * addend) { return *addend++; }
+inline int atomicDecrement(std::atomic<int> * addend) { return *addend--; }
+
 #elif COMPILER(GCC) && !CPU(SPARC64) // sizeof(_Atomic_word) != sizeof(int) on sparc64 gcc
 #define WTF_USE_LOCKFREE_THREADSAFEREFCOUNTED 1
 
@@ -227,9 +235,16 @@ inline void memoryBarrierBeforeUnlock() 
 
 #endif
 
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+typedef std::atomic<int> atomic_int;
+#else
+typedef int volatile atomic_int;
+#endif
+
 } // namespace WTF
 
 #if USE(LOCKFREE_THREADSAFEREFCOUNTED)
+using WTF::atomic_int;
 using WTF::atomicDecrement;
 using WTF::atomicIncrement;
 #endif
