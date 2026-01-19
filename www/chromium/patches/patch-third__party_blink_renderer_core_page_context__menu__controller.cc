$NetBSD: patch-third__party_blink_renderer_core_page_context__menu__controller.cc,v 1.13 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/page/context_menu_controller.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/core/page/context_menu_controller.cc
@@ -656,7 +656,7 @@ bool ContextMenuController::ShowContextM
     if (potential_image_node != nullptr &&
         IsA<HTMLCanvasElement>(potential_image_node)) {
       data.media_type = mojom::blink::ContextMenuDataMediaType::kCanvas;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // TODO(crbug.com/40902474): Support reading from the WebGPU front buffer
       // on Linux and remove the below code, which results in "Copy Image" and
       // "Save Image To" being grayed out in the context menu.
