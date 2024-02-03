$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_xml_xslt__processor.h,v 1.1 2024/02/03 05:30:55 markd Exp $

build with libxml-2.12

--- src/3rdparty/chromium/third_party/blink/renderer/core/xml/xslt_processor.h.orig	2022-12-08 15:31:50.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/xml/xslt_processor.h
@@ -79,7 +79,7 @@ class XSLTProcessor final : public Scrip
 
   void reset();
 
-  static void ParseErrorFunc(void* user_data, xmlError*);
+  static void ParseErrorFunc(void* user_data, const xmlError*);
   static void GenericErrorFunc(void* user_data, const char* msg, ...);
 
   // Only for libXSLT callbacks
