$NetBSD: patch-js_src_jspropertycacheinlines.h,v 1.1 2013/05/23 13:12:13 ryoon Exp $

--- js/src/jspropertycacheinlines.h.orig	2013-05-11 19:19:34.000000000 +0000
+++ js/src/jspropertycacheinlines.h
@@ -32,7 +32,7 @@ JS_ALWAYS_INLINE void
 js::PropertyCache::test(JSContext *cx, jsbytecode *pc, JSObject **obj,
                         JSObject **pobj, PropertyCacheEntry **entry, PropertyName **name)
 {
-    AutoAssertNoGC nogc;
+    js::AutoAssertNoGC nogc;
 
     JS_ASSERT(this == &cx->propertyCache());
 
@@ -65,7 +65,7 @@ JS_ALWAYS_INLINE bool
 js::PropertyCache::testForSet(JSContext *cx, jsbytecode *pc, JSObject *obj,
                               PropertyCacheEntry **entryp, JSObject **obj2p, PropertyName **namep)
 {
-    AutoAssertNoGC nogc;
+    js::AutoAssertNoGC nogc;
 
     JS_ASSERT(this == &cx->propertyCache());
 
