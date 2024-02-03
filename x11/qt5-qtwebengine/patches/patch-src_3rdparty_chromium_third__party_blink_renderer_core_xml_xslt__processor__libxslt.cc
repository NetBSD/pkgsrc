$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_xml_xslt__processor__libxslt.cc,v 1.1 2024/02/03 05:30:55 markd Exp $

build with libxml-2.12

--- src/3rdparty/chromium/third_party/blink/renderer/core/xml/xslt_processor_libxslt.cc.orig	2022-12-08 15:31:50.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/xml/xslt_processor_libxslt.cc
@@ -60,7 +60,7 @@ void XSLTProcessor::GenericErrorFunc(voi
   // It would be nice to do something with this error message.
 }
 
-void XSLTProcessor::ParseErrorFunc(void* user_data, xmlError* error) {
+void XSLTProcessor::ParseErrorFunc(void* user_data, const xmlError* error) {
   FrameConsole* console = static_cast<FrameConsole*>(user_data);
   if (!console)
     return;
