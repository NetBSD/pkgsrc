$NetBSD: patch-third__party_blink_renderer_core_paint_paint__layer.cc,v 1.18 2026/04/21 15:21:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/paint/paint_layer.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ third_party/blink/renderer/core/paint/paint_layer.cc
@@ -124,7 +124,7 @@ namespace blink {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 struct SameSizeAsPaintLayer : GarbageCollected<PaintLayer>, DisplayItemClient {
   // The bit fields may fit into the machine word of DisplayItemClient which
   // has only 8-bit data.
