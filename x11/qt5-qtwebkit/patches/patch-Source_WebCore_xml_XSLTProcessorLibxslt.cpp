$NetBSD: patch-Source_WebCore_xml_XSLTProcessorLibxslt.cpp,v 1.1 2024/01/27 18:06:36 wiz Exp $

Fix build with libxml2 2.12.

--- Source/WebCore/xml/XSLTProcessorLibxslt.cpp.orig	2020-03-04 17:16:37.000000000 +0000
+++ Source/WebCore/xml/XSLTProcessorLibxslt.cpp
@@ -78,7 +78,7 @@ void XSLTProcessor::genericErrorFunc(voi
     // It would be nice to do something with this error message.
 }
 
-void XSLTProcessor::parseErrorFunc(void* userData, xmlError* error)
+void XSLTProcessor::parseErrorFunc(void* userData, const xmlError* error)
 {
     PageConsoleClient* console = static_cast<PageConsoleClient*>(userData);
     if (!console)
