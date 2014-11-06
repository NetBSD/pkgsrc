$NetBSD: patch-js_src_frontend_BytecodeCompiler.cpp,v 1.1 2014/11/06 12:26:51 joerg Exp $

--- js/src/frontend/BytecodeCompiler.cpp.orig	2014-11-05 15:54:54.000000000 +0000
+++ js/src/frontend/BytecodeCompiler.cpp
@@ -544,7 +544,7 @@ CompileFunctionBody(JSContext *cx, Mutab
 
     RootedScriptSource sourceObject(cx, CreateScriptSourceObject(cx, options));
     if (!sourceObject)
-        return nullptr;
+        return false;
     ScriptSource *ss = sourceObject->source();
 
     SourceCompressionTask sct(cx);
