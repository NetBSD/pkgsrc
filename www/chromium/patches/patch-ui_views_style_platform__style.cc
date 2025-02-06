$NetBSD: patch-ui_views_style_platform__style.cc,v 1.1 2025/02/06 09:58:35 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/style/platform_style.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/views/style/platform_style.cc
@@ -17,7 +17,7 @@
 #include "ui/views/controls/focusable_border.h"
 #include "ui/views/controls/scrollbar/scroll_bar_views.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/controls/scrollbar/overlay_scroll_bar.h"
 #endif
 
@@ -50,7 +50,7 @@ const View::FocusBehavior PlatformStyle:
 // Linux clips bubble windows that extend outside their parent window
 // bounds.
 const bool PlatformStyle::kAdjustBubbleIfOffscreen =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     false;
 #else
     true;
@@ -59,7 +59,7 @@ const bool PlatformStyle::kAdjustBubbleI
 // static
 std::unique_ptr<ScrollBar> PlatformStyle::CreateScrollBar(
     ScrollBar::Orientation orientation) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<OverlayScrollBar>(orientation);
 #else
   return std::make_unique<ScrollBarViews>(orientation);
