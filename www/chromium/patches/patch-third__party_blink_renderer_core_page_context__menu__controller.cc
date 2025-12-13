$NetBSD: patch-third__party_blink_renderer_core_page_context__menu__controller.cc,v 1.11 2025/12/13 14:54:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/page/context_menu_controller.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ third_party/blink/renderer/core/page/context_menu_controller.cc
@@ -650,7 +650,7 @@ bool ContextMenuController::ShowContextM
     if (potential_image_node != nullptr &&
         IsA<HTMLCanvasElement>(potential_image_node)) {
       data.media_type = mojom::blink::ContextMenuDataMediaType::kCanvas;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // TODO(crbug.com/40902474): Support reading from the WebGPU front buffer
       // on Linux and remove the below code, which results in "Copy Image" and
       // "Save Image To" being grayed out in the context menu.
