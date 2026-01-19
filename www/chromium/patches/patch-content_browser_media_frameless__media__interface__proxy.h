$NetBSD: patch-content_browser_media_frameless__media__interface__proxy.h,v 1.14 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/media/frameless_media_interface_proxy.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/browser/media/frameless_media_interface_proxy.h
@@ -19,7 +19,7 @@
 #include "mojo/public/cpp/bindings/receiver_set.h"
 #include "mojo/public/cpp/bindings/remote.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/mojo/mojom/video_decoder.mojom.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -96,7 +96,7 @@ class FramelessMediaInterfaceProxy final
   // Connections to the renderer.
   mojo::ReceiverSet<media::mojom::InterfaceFactory> receivers_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Connection to the InterfaceFactory that lives in a utility process.
   // This is only used for out-of-process video decoding and only when the
   // FramelessMediaInterfaceProxy is created without a RenderProcessHost
