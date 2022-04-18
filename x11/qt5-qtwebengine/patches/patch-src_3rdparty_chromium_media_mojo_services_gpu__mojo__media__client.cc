$NetBSD: patch-src_3rdparty_chromium_media_mojo_services_gpu__mojo__media__client.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/media/mojo/services/gpu_mojo_media_client.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/media/mojo/services/gpu_mojo_media_client.cc
@@ -67,7 +67,7 @@ namespace media {
 namespace {
 
 #if defined(OS_ANDROID) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_WIN) || defined(OS_LINUX)
+    defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 gpu::CommandBufferStub* GetCommandBufferStub(
     scoped_refptr<base::SingleThreadTaskRunner> gpu_task_runner,
     base::WeakPtr<MediaGpuChannelManager> media_gpu_channel_manager,
@@ -299,7 +299,7 @@ std::unique_ptr<VideoDecoder> GpuMojoMed
       }
 
 #elif defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 #if defined(OS_WIN)
       // Don't instantiate the DXVA decoder if it's not supported.
       if (gpu_workarounds_.disable_dxva_video_decoder)
