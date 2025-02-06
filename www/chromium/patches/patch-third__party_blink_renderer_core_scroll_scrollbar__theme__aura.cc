$NetBSD: patch-third__party_blink_renderer_core_scroll_scrollbar__theme__aura.cc,v 1.1 2025/02/06 09:58:23 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc
@@ -148,7 +148,7 @@ bool ScrollbarThemeAura::SupportsDragSna
 // is true for at least GTK and QT apps).
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
@@ -418,7 +418,7 @@ bool ScrollbarThemeAura::ShouldCenterOnT
                                              const WebMouseEvent& event) const {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   if (event.button == WebPointerProperties::Button::kMiddle)
     return true;
 #endif
