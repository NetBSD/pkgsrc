$NetBSD: patch-third__party_blink_renderer_core_paint_paint__layer.cc,v 1.3 2025/07/07 09:23:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/paint/paint_layer.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ third_party/blink/renderer/core/paint/paint_layer.cc
@@ -125,7 +125,7 @@ namespace blink {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 struct SameSizeAsPaintLayer : GarbageCollected<PaintLayer>, DisplayItemClient {
   // The bit fields may fit into the machine word of DisplayItemClient which
   // has only 8-bit data.
