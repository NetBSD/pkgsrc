$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_xml_xslt__processor.h,v 1.3 2024/02/12 00:52:49 markd Exp $

build with libxml-2.12

--- src/3rdparty/chromium/third_party/blink/renderer/core/xml/xslt_processor.h.orig	2022-12-08 15:31:50.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/xml/xslt_processor.h
@@ -79,7 +79,11 @@ class XSLTProcessor final : public Scrip
 
   void reset();
 
+#if LIBXML_VERSION >= 21200
+  static void ParseErrorFunc(void* user_data, const xmlError*);
+#else
   static void ParseErrorFunc(void* user_data, xmlError*);
+#endif
   static void GenericErrorFunc(void* user_data, const char* msg, ...);
 
   // Only for libXSLT callbacks
