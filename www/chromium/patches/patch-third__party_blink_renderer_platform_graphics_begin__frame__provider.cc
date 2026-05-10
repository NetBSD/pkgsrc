$NetBSD: patch-third__party_blink_renderer_platform_graphics_begin__frame__provider.cc,v 1.19 2026/05/10 15:30:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/graphics/begin_frame_provider.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ third_party/blink/renderer/platform/graphics/begin_frame_provider.cc
@@ -71,7 +71,11 @@ void BeginFrameProvider::CreateComposito
 
   // Once we are using RAF, this thread is driving user interactive display
   // updates. Update priority accordingly.
+  // pledge(2)
+  // stop this baloney
+#if !defined(OS_OPENBSD)
   lease_.emplace(base::ThreadType::kPresentation);
+#endif
 
   mojo::Remote<mojom::blink::EmbeddedFrameSinkProvider> provider;
   Platform::Current()->GetBrowserInterfaceBroker()->GetInterface(
