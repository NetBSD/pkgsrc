$NetBSD: patch-js_src_frontend_ParseMaps.cpp,v 1.3 2014/02/20 13:19:03 ryoon Exp $

--- js/src/frontend/ParseMaps.cpp.orig	2013-09-10 03:43:34.000000000 +0000
+++ js/src/frontend/ParseMaps.cpp
@@ -132,5 +132,5 @@ frontend::InitAtomMap(JSContext *cx, fro
     }
 }
 
-template class js::frontend::AtomDecls<FullParseHandler>;
-template class js::frontend::AtomDecls<SyntaxParseHandler>;
+template class frontend::AtomDecls<FullParseHandler>;
+template class frontend::AtomDecls<SyntaxParseHandler>;
