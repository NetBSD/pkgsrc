$NetBSD: patch-third__party_blink_renderer_core_layout_layout__view.cc,v 1.1 2025/02/06 09:58:23 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/layout/layout_view.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/blink/renderer/core/layout/layout_view.cc
@@ -73,7 +73,7 @@
 #include "ui/display/screen_info.h"
 #include "ui/gfx/geometry/quad_f.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/platform/fonts/font_cache.h"
 #endif
 
@@ -769,7 +769,7 @@ void LayoutView::LayoutRoot() {
     intrinsic_logical_widths_ = LogicalWidth();
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The font code in FontPlatformData does not have a direct connection to the
   // document, the frame or anything from which we could retrieve the device
   // scale factor. After using zoom for DSF, the GraphicsContext does only ever
