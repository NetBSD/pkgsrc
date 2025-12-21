$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_paint_paint__layer.cc,v 1.1 2025/12/21 09:38:40 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/core/paint/paint_layer.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/paint/paint_layer.cc
@@ -120,7 +120,7 @@ namespace blink {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 struct SameSizeAsPaintLayer : GarbageCollected<PaintLayer>, DisplayItemClient {
   // The bit fields may fit into the machine word of DisplayItemClient which
   // has only 8-bit data.
