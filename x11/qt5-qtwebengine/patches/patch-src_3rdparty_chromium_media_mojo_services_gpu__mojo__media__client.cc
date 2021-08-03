$NetBSD: patch-src_3rdparty_chromium_media_mojo_services_gpu__mojo__media__client.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/media/mojo/services/gpu_mojo_media_client.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ src/3rdparty/chromium/media/mojo/services/gpu_mojo_media_client.cc
@@ -63,7 +63,7 @@ namespace media {
 namespace {
 
 #if defined(OS_ANDROID) || defined(OS_CHROMEOS) || defined(OS_MACOSX) || \
-    defined(OS_WIN) || defined(OS_LINUX)
+    defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 gpu::CommandBufferStub* GetCommandBufferStub(
     scoped_refptr<base::SingleThreadTaskRunner> gpu_task_runner,
     base::WeakPtr<MediaGpuChannelManager> media_gpu_channel_manager,
@@ -280,7 +280,7 @@ std::unique_ptr<VideoDecoder> GpuMojoMed
                                 command_buffer_id->route_id));
       }
 
-#elif defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 #if defined(OS_WIN)
       // Don't instantiate the DXVA decoder if it's not supported.
       if (gpu_workarounds_.disable_dxva_video_decoder)
