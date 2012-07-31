$NetBSD: patch-Source_WebCore_xml_XPathParser.cpp,v 1.1 2012/07/31 13:59:55 prlw1 Exp $

Fix for Bug 92264: Build fix with newer bison 2.6.
https://bugs.webkit.org/show_bug.cgi?id=92264

--- Source/WebCore/xml/XPathParser.cpp.orig	2012-04-22 23:27:00.000000000 +0000
+++ Source/WebCore/xml/XPathParser.cpp
@@ -32,24 +32,21 @@
 #include "XPathEvaluator.h"
 #include "XPathException.h"
 #include "XPathNSResolver.h"
+#include "XPathPath.h"
 #include "XPathStep.h"
 #include <wtf/StdLibExtras.h>
 #include <wtf/text/StringHash.h>
 
-int xpathyyparse(void*);
-
+using namespace WebCore;
 using namespace WTF;
 using namespace Unicode;
+using namespace XPath;
 
-namespace WebCore {
-namespace XPath {
-
-class LocationPath;
-
-#include "XPathGrammar.h"    
+extern int xpathyyparse(WebCore::XPath::Parser*);
+#include "XPathGrammar.h"
 
 Parser* Parser::currentParser = 0;
-    
+
 enum XMLCat { NameStart, NameCont, NotPartOfName };
 
 typedef HashMap<String, Step::Axis> AxisNamesMap;
@@ -630,5 +627,3 @@ void Parser::deleteNodeTest(Step::NodeTe
     delete t;
 }
 
-}
-}
