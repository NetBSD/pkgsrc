$NetBSD: patch-src_3rdparty_webkit_Source_JavaScriptCore_wtf_Atomics.h,v 1.1 2013/05/09 14:07:08 joerg Exp $

--- src/3rdparty/webkit/Source/JavaScriptCore/wtf/Atomics.h.orig	2012-11-23 10:10:05.000000000 +0000
+++ src/3rdparty/webkit/Source/JavaScriptCore/wtf/Atomics.h
@@ -61,7 +61,9 @@
 
 #include "Platform.h"
 
-#if OS(WINDOWS)
+#if __cplusplus >= 201103L
+#include <atomic>
+#elif OS(WINDOWS)
 #include <windows.h>
 #elif OS(DARWIN)
 #include <libkern/OSAtomic.h>
@@ -79,7 +82,11 @@
 
 namespace WTF {
 
-#if OS(WINDOWS)
+#if __cplusplus >= 201103L
+#define WTF_USE_LOCKFREE_THREADSAFEREFCOUNTED 1
+inline int atomicIncrement(std::atomic<int> * addend) { return *addend++; }
+inline int atomicDecrement(std::atomic<int> * addend) { return *addend--; }
+#elif OS(WINDOWS)
 #define WTF_USE_LOCKFREE_THREADSAFEREFCOUNTED 1
 
 #if COMPILER(MINGW) || COMPILER(MSVC7_OR_LOWER) || OS(WINCE)
@@ -114,9 +126,15 @@ inline int atomicDecrement(int volatile*
 
 #endif
 
+#if __cplusplus >= 201103L
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
