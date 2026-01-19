$NetBSD: patch-third__party_blink_renderer_core_xml_xslt__processor.h,v 1.14 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/xml/xslt_processor.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/core/xml/xslt_processor.h
@@ -89,7 +89,11 @@ class XSLTProcessor final : public Scrip
 
   void reset();
 
+#if (LIBXML_VERSION >= 21200)
   static void ParseErrorFunc(void* user_data, const xmlError*);
+#else
+  static void ParseErrorFunc(void* user_data, xmlError*);
+#endif
   static void GenericErrorFunc(void* user_data, const char* msg, ...);
 
   // Only for libXSLT callbacks
