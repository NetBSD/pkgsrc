$NetBSD: patch-mozilla_js_src_vm_WeakMapPtr.cpp,v 1.1 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/js/src/vm/WeakMapPtr.cpp.orig	2014-10-14 06:36:24.000000000 +0000
+++ mozilla/js/src/vm/WeakMapPtr.cpp
@@ -120,9 +120,9 @@ JS::WeakMapPtr<K, V>::put(JSContext *cx,
 // Supported specializations of JS::WeakMap:
 //
 
-template class JS::WeakMapPtr<JSObject*, JSObject*>;
+template class JS_PUBLIC_API(JS::WeakMapPtr)<JSObject*, JSObject*>;
 
 #ifdef DEBUG
 // Nobody's using this at the moment, but we want to make sure it compiles.
-template class JS::WeakMapPtr<JSObject*, JS::Value>;
+template class JS_PUBLIC_API(JS::WeakMapPtr)<JSObject*, JS::Value>;
 #endif
