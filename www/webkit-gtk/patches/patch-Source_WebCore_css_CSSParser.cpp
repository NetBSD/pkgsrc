$NetBSD: patch-Source_WebCore_css_CSSParser.cpp,v 1.1 2012/07/31 13:59:55 prlw1 Exp $

Fix for Bug 92264: Build fix with newer bison 2.6.
https://bugs.webkit.org/show_bug.cgi?id=92264

--- Source/WebCore/css/CSSParser.cpp.orig	2012-04-24 01:35:25.000000000 +0000
+++ Source/WebCore/css/CSSParser.cpp
@@ -101,7 +101,7 @@
 extern int cssyydebug;
 #endif
 
-extern int cssyyparse(void* parser);
+extern int cssyyparse(WebCore::CSSParser*);
 
 using namespace std;
 using namespace WTF;
