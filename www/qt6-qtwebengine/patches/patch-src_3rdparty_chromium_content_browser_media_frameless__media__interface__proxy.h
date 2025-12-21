$NetBSD: patch-src_3rdparty_chromium_content_browser_media_frameless__media__interface__proxy.h,v 1.1 2025/12/21 09:38:26 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/media/frameless_media_interface_proxy.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/content/browser/media/frameless_media_interface_proxy.h
@@ -19,7 +19,7 @@
 #include "mojo/public/cpp/bindings/receiver_set.h"
 #include "mojo/public/cpp/bindings/remote.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/mojo/mojom/stable/stable_video_decoder.mojom.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -105,7 +105,7 @@ class FramelessMediaInterfaceProxy final
   // Connections to the renderer.
   mojo::ReceiverSet<media::mojom::InterfaceFactory> receivers_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Connection to the StableVideoDecoderFactory that lives in a utility
   // process. This is only used for out-of-process video decoding and only when
   // the FramelessMediaInterfaceProxy is created without a RenderProcessHost
