$NetBSD: patch-src_3rdparty_chromium_gpu_command__buffer_service_external__semaphore.cc,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/gpu/command_buffer/service/external_semaphore.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/gpu/command_buffer/service/external_semaphore.cc
@@ -39,7 +39,7 @@ GLuint ImportSemaphoreHandleToGLSemaphor
       },
       base::Time::Now()));
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   if (handle.vk_handle_type() !=
       VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT) {
     DLOG(ERROR) << "Importing semaphore handle of unexpected type:"
