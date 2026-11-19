$NetBSD: patch-third__party_blink_renderer_core_page_context__menu__controller.cc,v 1.32 2026/11/19 19:46:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/page/context_menu_controller.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ third_party/blink/renderer/core/page/context_menu_controller.cc
@@ -723,7 +723,7 @@ bool ContextMenuController::ShowContextM
       data.media_type = mojom::blink::ContextMenuDataMediaType::kCanvas;
       const auto* canvas = To<HTMLCanvasElement>(potential_image_node);
       data.has_image_contents = canvas->OriginClean();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // TODO(crbug.com/40902474): Support reading from the WebGPU front buffer
       // on Linux and remove the below code, which results in "Copy Image" and
       // "Save Image To" being grayed out in the context menu.
