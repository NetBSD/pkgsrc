$NetBSD: patch-mozilla_js_src_frontend_ParseMaps.cpp,v 1.1 2013/09/28 14:37:05 ryoon Exp $

--- mozilla/js/src/frontend/ParseMaps.cpp.orig	2013-09-16 18:26:39.000000000 +0000
+++ mozilla/js/src/frontend/ParseMaps.cpp
@@ -132,5 +132,5 @@ frontend::InitAtomMap(JSContext *cx, fro
     }
 }
 
-template class js::frontend::AtomDecls<FullParseHandler>;
-template class js::frontend::AtomDecls<SyntaxParseHandler>;
+template class frontend::AtomDecls<FullParseHandler>;
+template class frontend::AtomDecls<SyntaxParseHandler>;
