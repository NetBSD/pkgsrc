$NetBSD: patch-mozilla_js_src_jsscript.cpp,v 1.1 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/js/src/jsscript.cpp.orig	2013-06-20 04:35:08.000000000 +0000
+++ mozilla/js/src/jsscript.cpp
@@ -1629,7 +1629,11 @@ ScriptDataSize(uint32_t nbindings, uint3
     if (ntrynotes != 0)
         size += sizeof(TryNoteArray) + ntrynotes * sizeof(JSTryNote);
 
-    size += nbindings * sizeof(Binding);
+    if (nbindings != 0) {
+        // account for padding pre bindings
+        size = JS_ROUNDUP(size, JS_ALIGNMENT_OF(Binding)) + nbindings * sizeof(Binding);
+    }
+
     return size;
 }
 
@@ -1757,6 +1761,11 @@ JSScript::partiallyInit(JSContext *cx, H
         cursor += vectorSize;
     }
 
+    if (script->bindings.count() != 0) {
+	// Make sure bindings are sufficiently aligned.
+	cursor = reinterpret_cast<uint8_t*>
+	    (JS_ROUNDUP(reinterpret_cast<uintptr_t>(cursor), JS_ALIGNMENT_OF(Binding)));
+    }
     cursor = script->bindings.switchToScriptStorage(reinterpret_cast<Binding *>(cursor));
 
     JS_ASSERT(cursor == script->data + size);
