$NetBSD: patch-js_src_frontend_BytecodeCompiler.cpp,v 1.3 2015/06/02 20:04:43 joerg Exp $

--- js/src/frontend/BytecodeCompiler.cpp.orig	2015-05-30 18:55:53.000000000 +0000
+++ js/src/frontend/BytecodeCompiler.cpp
@@ -544,7 +544,7 @@ CompileFunctionBody(JSContext* cx, Mutab
 
     RootedScriptSource sourceObject(cx, CreateScriptSourceObject(cx, options));
     if (!sourceObject)
-        return nullptr;
+        return false;
     ScriptSource* ss = sourceObject->source();
 
     SourceCompressionTask sct(cx);
