$NetBSD: patch-content_renderer_render__thread__impl.cc,v 1.19 2026/05/10 15:29:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/renderer/render_thread_impl.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ content/renderer/render_thread_impl.cc
@@ -205,6 +205,8 @@
 
 #if BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
+#elif BUILDFLAG(IS_BSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -951,7 +953,7 @@ media::GpuVideoAcceleratorFactories* Ren
       viz::command_buffer_metrics::ContextType::MEDIA);
 
   const bool enable_video_decode_accelerator =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FeatureList::IsEnabled(media::kAcceleratedVideoDecodeLinux) &&
 #endif  // BUILDFLAG(IS_LINUX)
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode) &&
@@ -960,7 +962,7 @@ media::GpuVideoAcceleratorFactories* Ren
        gpu::kGpuFeatureStatusEnabled);
 
   const bool enable_video_encode_accelerator =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FeatureList::IsEnabled(media::kAcceleratedVideoEncodeLinux) &&
 #else
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoEncode) &&
@@ -1708,7 +1710,7 @@ RenderThreadImpl::CreateMediaMojoCodecFa
     bool enable_video_encode_accelerator) {
   mojo::PendingRemote<media::mojom::VideoEncodeAcceleratorProvider>
       vea_provider;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(media::kUseOutOfProcessVideoEncoding)) {
     BindHostReceiver(vea_provider.InitWithNewPipeAndPassReceiver());
   } else {
