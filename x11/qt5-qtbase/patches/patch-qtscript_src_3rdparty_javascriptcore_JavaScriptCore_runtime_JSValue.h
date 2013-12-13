$NetBSD: patch-qtscript_src_3rdparty_javascriptcore_JavaScriptCore_runtime_JSValue.h,v 1.1 2013/12/13 14:38:35 ryoon Exp $

--- qtscript/src/3rdparty/javascriptcore/JavaScriptCore/runtime/JSValue.h.orig	2013-11-27 01:00:27.000000000 +0000
+++ qtscript/src/3rdparty/javascriptcore/JavaScriptCore/runtime/JSValue.h
@@ -491,7 +491,7 @@ namespace JSC {
             u.asBits.tag = CellTag;
         else
             u.asBits.tag = EmptyValueTag;
-        u.asBits.payload = reinterpret_cast<int32_t>(ptr);
+        u.asBits.payload = reinterpret_cast<intptr_t>(ptr);
 #if ENABLE(JSC_ZOMBIES)
         ASSERT(!isZombie());
 #endif
@@ -503,7 +503,7 @@ namespace JSC {
             u.asBits.tag = CellTag;
         else
             u.asBits.tag = EmptyValueTag;
-        u.asBits.payload = reinterpret_cast<int32_t>(const_cast<JSCell*>(ptr));
+        u.asBits.payload = reinterpret_cast<intptr_t>(const_cast<JSCell*>(ptr));
 #if ENABLE(JSC_ZOMBIES)
         ASSERT(!isZombie());
 #endif
