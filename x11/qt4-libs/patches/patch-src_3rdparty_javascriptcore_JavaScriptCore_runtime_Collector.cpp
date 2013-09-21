$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_runtime_Collector.cpp,v 1.1 2013/09/21 09:40:36 joerg Exp $

--- src/3rdparty/javascriptcore/JavaScriptCore/runtime/Collector.cpp.orig	2013-09-20 19:13:54.000000000 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/runtime/Collector.cpp
@@ -823,10 +823,8 @@ void Heap::markConservatively(MarkStack&
 
 void NEVER_INLINE Heap::markCurrentThreadConservativelyInternal(MarkStack& markStack)
 {
-    void* dummy;
-    void* stackPointer = &dummy;
     void* stackBase = currentThreadStackBase();
-    markConservatively(markStack, stackPointer, stackBase);
+    markConservatively(markStack, __builtin_frame_address(0), stackBase);
 }
 
 #if COMPILER(GCC)
