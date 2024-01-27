$NetBSD: patch-Source_WebCore_xml_XSLTProcessor.h,v 1.1 2024/01/27 17:28:11 wiz Exp $

Fix build with libxml2 2.12.

--- Source/WebCore/xml/XSLTProcessor.h.orig	2024-01-27 17:15:35.512091087 +0000
+++ Source/WebCore/xml/XSLTProcessor.h
@@ -61,7 +61,7 @@ public:
 
     void reset();
 
-    static void parseErrorFunc(void* userData, xmlError*);
+    static void parseErrorFunc(void* userData, const xmlError*);
     static void genericErrorFunc(void* userData, const char* msg, ...);
     
     // Only for libXSLT callbacks
