$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_paint_paint__layer.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/core/paint/paint_layer.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/paint/paint_layer.cc
@@ -110,7 +110,7 @@ namespace {
 static CompositingQueryMode g_compositing_query_mode =
     kCompositingQueriesAreOnlyAllowedInCertainDocumentLifecyclePhases;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 struct SameSizeAsPaintLayer : DisplayItemClient {
   // The bit fields may fit into the machine word of DisplayItemClient which
   // has only 8-bit data.
