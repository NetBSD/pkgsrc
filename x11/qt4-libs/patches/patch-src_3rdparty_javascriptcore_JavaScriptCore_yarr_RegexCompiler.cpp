$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_yarr_RegexCompiler.cpp,v 1.1 2018/01/17 18:37:34 markd Exp $

function doesnt return a boolean

--- src/3rdparty/javascriptcore/JavaScriptCore/yarr/RegexCompiler.cpp.orig	2015-05-07 14:14:47.000000000 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/yarr/RegexCompiler.cpp
@@ -719,7 +719,7 @@ const char* compileRegex(const UString&
 
     constructor.setupOffsets();
 
-    return false;
+    return 0;
 };
 
 
