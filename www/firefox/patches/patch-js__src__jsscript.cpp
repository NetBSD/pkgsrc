$NetBSD: patch-js__src__jsscript.cpp,v 1.1 2013/06/21 23:11:42 ryoon Exp $

# HG changeset patch
# User Martin Husemann <martin@netbsd.org>
# Date 1370581392 25200
# Node ID 88d63d06dec9a9d12a8e1200f1117d648fc386e2
# Parent  1c14b70442b380d63119dbc7d3c465e9c0e655fd
Bug 870325 - Fix alignment of Bindings on SPARC64.  r=nnethercote.

diff js/src/jsscript.cpp js/src/jsscript.cpp
--- js/src/jsscript.cpp.orig	2013-05-11 21:19:34.000000000 +0200
+++ js/src/jsscript.cpp	2013-06-10 13:58:15.000000000 +0200
@@ -1695,7 +1695,11 @@
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
 
@@ -1822,6 +1826,11 @@
         cursor += vectorSize;
     }
 
+    if (script->bindings.count() != 0) {
+	// Make sure bindings are sufficiently aligned.
+	cursor = reinterpret_cast<uint8_t*>
+	    (JS_ROUNDUP(reinterpret_cast<uintptr_t>(cursor), JS_ALIGNMENT_OF(Binding)));
+    }
     cursor = script->bindings.switchToScriptStorage(reinterpret_cast<Binding *>(cursor));
 
     JS_ASSERT(cursor == script->data + size);
