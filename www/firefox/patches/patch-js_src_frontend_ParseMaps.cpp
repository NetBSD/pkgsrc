$NetBSD: patch-js_src_frontend_ParseMaps.cpp,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- js/src/frontend/ParseMaps.cpp.orig	2014-01-28 04:03:45.000000000 +0000
+++ js/src/frontend/ParseMaps.cpp
@@ -132,5 +132,5 @@ frontend::InitAtomMap(frontend::AtomInde
     }
 }
 
-template class js::frontend::AtomDecls<FullParseHandler>;
-template class js::frontend::AtomDecls<SyntaxParseHandler>;
+template class frontend::AtomDecls<FullParseHandler>;
+template class frontend::AtomDecls<SyntaxParseHandler>;
