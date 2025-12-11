$NetBSD: patch-third__party_blink_renderer_core_xml_xslt__processor.h,v 1.11 2025/12/11 09:13:44 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/xml/xslt_processor.h.orig	2025-11-19 21:40:05.000000000 +0000
+++ third_party/blink/renderer/core/xml/xslt_processor.h
@@ -82,7 +82,11 @@ class XSLTProcessor final : public Scrip
 
   void reset();
 
+#if (LIBXML_VERSION >= 21200)
   static void ParseErrorFunc(void* user_data, const xmlError*);
+#else
+  static void ParseErrorFunc(void* user_data, xmlError*);
+#endif
   static void GenericErrorFunc(void* user_data, const char* msg, ...);
 
   // Only for libXSLT callbacks
