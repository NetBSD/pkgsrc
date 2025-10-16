$NetBSD: patch-content_browser_renderer__host_render__process__host__impl.h,v 1.8 2025/10/16 19:43:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/render_process_host_impl.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ content/browser/renderer_host/render_process_host_impl.h
@@ -101,7 +101,7 @@
 #include "media/fuchsia_media_codec_provider_impl.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/browser/child_thread_type_switcher_linux.h"
 #include "media/mojo/mojom/video_encode_accelerator.mojom.h"
 #endif
@@ -994,7 +994,7 @@ class CONTENT_EXPORT RenderProcessHostIm
     mojo::Remote<media::mojom::VideoEncodeAcceleratorProviderFactory>
         video_encode_accelerator_factory_remote_;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     ChildThreadTypeSwitcher child_thread_type_switcher_;
 #endif
   };
@@ -1237,7 +1237,7 @@ class CONTENT_EXPORT RenderProcessHostIm
   // if the request isn't handled on the IO thread.
   void OnBindHostReceiver(mojo::GenericPendingReceiver receiver);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Provides /proc/{renderer pid}/status and statm files for the renderer,
   // because the files are required to calculate the renderer's private
   // footprint on Chromium Linux. Regarding MacOS X and Windows, we have
