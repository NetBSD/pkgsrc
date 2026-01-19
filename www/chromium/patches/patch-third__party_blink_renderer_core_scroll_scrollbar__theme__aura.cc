$NetBSD: patch-third__party_blink_renderer_core_scroll_scrollbar__theme__aura.cc,v 1.14 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc
@@ -122,7 +122,7 @@ bool ScrollbarThemeAura::SupportsDragSna
 // Disable snapback on desktop Linux to better integrate with the desktop
 // behavior. Typically, Linux apps do not implement scrollbar snapback (this
 // is true for at least GTK and QT apps).
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
@@ -396,7 +396,7 @@ ScrollbarPart ScrollbarThemeAura::PartsT
 
 bool ScrollbarThemeAura::ShouldCenterOnThumb(const Scrollbar& scrollbar,
                                              const WebMouseEvent& event) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event.button == WebPointerProperties::Button::kMiddle)
     return true;
 #endif
