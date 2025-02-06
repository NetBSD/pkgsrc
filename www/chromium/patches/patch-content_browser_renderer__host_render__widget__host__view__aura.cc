$NetBSD: patch-content_browser_renderer__host_render__widget__host__view__aura.cc,v 1.1 2025/02/06 09:58:06 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/renderer_host/render_widget_host_view_aura.cc
@@ -121,7 +121,7 @@
 #include "ui/gfx/gdi_util.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/accessibility/platform/browser_accessibility_auralinux.h"
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/text_input_flags.h"
@@ -484,7 +484,7 @@ gfx::NativeViewAccessible RenderWidgetHo
     return ToBrowserAccessibilityWin(manager->GetBrowserAccessibilityRoot())
         ->GetCOM();
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::BrowserAccessibilityManager* manager =
       host()->GetOrCreateRootBrowserAccessibilityManager();
   if (manager && manager->GetBrowserAccessibilityRoot())
@@ -1745,7 +1745,7 @@ bool RenderWidgetHostViewAura::ShouldDoL
   return host() && host()->delegate() && host()->delegate()->ShouldDoLearning();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool RenderWidgetHostViewAura::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
@@ -2654,7 +2654,7 @@ bool RenderWidgetHostViewAura::NeedsInpu
 }
 
 bool RenderWidgetHostViewAura::NeedsMouseCapture() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return NeedsInputGrab();
 #else
   return false;
@@ -2838,7 +2838,7 @@ void RenderWidgetHostViewAura::ForwardKe
   if (!target_host)
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = ui::LinuxUi::instance();
   std::vector<ui::TextEditCommandAuraLinux> commands;
   if (!event.skip_if_unhandled && linux_ui && event.os_event &&
