$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_runtime_JSValue.h,v 1.1 2014/12/30 17:23:47 adam Exp $

--- src/3rdparty/javascriptcore/JavaScriptCore/runtime/JSValue.h.orig	2013-11-27 01:00:27.000000000 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/runtime/JSValue.h
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
