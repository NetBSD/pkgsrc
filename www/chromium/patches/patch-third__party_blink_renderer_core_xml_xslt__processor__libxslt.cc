$NetBSD: patch-third__party_blink_renderer_core_xml_xslt__processor__libxslt.cc,v 1.29 2026/10/13 13:16:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/xml/xslt_processor_libxslt.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ third_party/blink/renderer/core/xml/xslt_processor_libxslt.cc
@@ -68,7 +68,11 @@ void XSLTProcessor::GenericErrorFunc(voi
   // It would be nice to do something with this error message.
 }
 
+#if (LIBXML_VERSION >= 21200)
 void XSLTProcessor::ParseErrorFunc(void* user_data, const xmlError* error) {
+#else
+void XSLTProcessor::ParseErrorFunc(void* user_data, xmlError* error) {
+#endif
   FrameConsole* console = static_cast<FrameConsole*>(user_data);
   if (!console)
     return;
