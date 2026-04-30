$NetBSD: patch-src_3rdparty_chromium_ui_views_style_platform__style.cc,v 1.2 2026/04/30 06:39:45 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/views/style/platform_style.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/ui/views/style/platform_style.cc
@@ -23,7 +23,7 @@
 #include "ui/views/controls/focusable_border.h"
 #include "ui/views/controls/scrollbar/scroll_bar_views.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/controls/scrollbar/overlay_scroll_bar.h"
 #endif
 #endif
@@ -35,7 +35,7 @@ namespace views {
 // static
 std::unique_ptr<ScrollBar> PlatformStyle::CreateScrollBar(
     ScrollBar::Orientation orientation) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<OverlayScrollBar>(orientation);
 #else
   return std::make_unique<ScrollBarViews>(orientation);
