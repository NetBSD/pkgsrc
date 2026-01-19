$NetBSD: patch-ui_views_style_platform__style.cc,v 1.14 2026/01/19 16:14:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/style/platform_style.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/views/style/platform_style.cc
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
