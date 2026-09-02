$NetBSD: patch-third__party_blink_renderer_core_page_context__menu__controller.cc,v 1.24 2026/09/02 13:13:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/page/context_menu_controller.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/blink/renderer/core/page/context_menu_controller.cc
@@ -680,7 +680,7 @@ bool ContextMenuController::ShowContextM
     if (potential_image_node != nullptr &&
         IsA<HTMLCanvasElement>(potential_image_node)) {
       data.media_type = mojom::blink::ContextMenuDataMediaType::kCanvas;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // TODO(crbug.com/40902474): Support reading from the WebGPU front buffer
       // on Linux and remove the below code, which results in "Copy Image" and
       // "Save Image To" being grayed out in the context menu.
