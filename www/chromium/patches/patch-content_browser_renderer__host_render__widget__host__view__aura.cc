$NetBSD: patch-content_browser_renderer__host_render__widget__host__view__aura.cc,v 1.25 2026/09/02 13:13:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ content/browser/renderer_host/render_widget_host_view_aura.cc
@@ -134,7 +134,7 @@
 #include "ui/gfx/win/gdi_util.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/accessibility/platform/browser_accessibility_auralinux.h"
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/text_input_flags.h"
@@ -580,7 +580,7 @@ gfx::NativeViewAccessible RenderWidgetHo
     return ToBrowserAccessibilityWin(manager->GetBrowserAccessibilityRoot())
         ->GetCOM();
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::BrowserAccessibilityManager* manager =
       host()->GetOrCreateRootBrowserAccessibilityManager();
   if (manager && manager->GetBrowserAccessibilityRoot())
@@ -2062,7 +2062,7 @@ bool RenderWidgetHostViewAura::ShouldDoL
   return host() && host()->delegate() && host()->delegate()->ShouldDoLearning();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool RenderWidgetHostViewAura::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
@@ -3151,7 +3151,7 @@ bool RenderWidgetHostViewAura::NeedsInpu
 }
 
 bool RenderWidgetHostViewAura::NeedsMouseCapture() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return NeedsInputGrab();
 #else
   return false;
@@ -3379,7 +3379,7 @@ void RenderWidgetHostViewAura::ForwardKe
   if (!target_host)
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = ui::LinuxUi::instance();
   if (!event.skip_if_unhandled && linux_ui && event.os_event) {
     const auto command = linux_ui->GetTextEditCommandForEvent(
