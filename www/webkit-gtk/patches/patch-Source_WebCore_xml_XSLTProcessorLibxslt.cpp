$NetBSD: patch-Source_WebCore_xml_XSLTProcessorLibxslt.cpp,v 1.1 2024/01/27 17:28:11 wiz Exp $

Fix build with libxml2 2.12.

--- Source/WebCore/xml/XSLTProcessorLibxslt.cpp.orig	2024-01-27 17:15:52.019994538 +0000
+++ Source/WebCore/xml/XSLTProcessorLibxslt.cpp
@@ -61,7 +61,7 @@ void XSLTProcessor::genericErrorFunc(voi
     // It would be nice to do something with this error message.
 }
 
-void XSLTProcessor::parseErrorFunc(void* userData, xmlError* error)
+void XSLTProcessor::parseErrorFunc(void* userData, const xmlError* error)
 {
     PageConsoleClient* console = static_cast<PageConsoleClient*>(userData);
     if (!console)
