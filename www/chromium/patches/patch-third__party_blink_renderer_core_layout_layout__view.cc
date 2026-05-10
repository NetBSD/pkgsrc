$NetBSD: patch-third__party_blink_renderer_core_layout_layout__view.cc,v 1.19 2026/05/10 15:30:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/layout/layout_view.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ third_party/blink/renderer/core/layout/layout_view.cc
@@ -76,7 +76,7 @@
 #include "ui/display/screen_info.h"
 #include "ui/gfx/geometry/quad_f.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/platform/fonts/font_cache.h"
 #endif
 
@@ -867,7 +867,7 @@ void LayoutView::LayoutRoot() {
     intrinsic_logical_widths_ = LogicalWidth();
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The font code in FontPlatformData does not have a direct connection to the
   // document, the frame or anything from which we could retrieve the device
   // scale factor. After using zoom for DSF, the GraphicsContext does only ever
