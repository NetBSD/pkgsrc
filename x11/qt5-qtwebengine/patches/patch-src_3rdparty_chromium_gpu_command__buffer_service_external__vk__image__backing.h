$NetBSD: patch-src_3rdparty_chromium_gpu_command__buffer_service_external__vk__image__backing.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/gpu/command_buffer/service/external_vk_image_backing.h.orig	2020-07-08 21:41:48.000000000 +0000
+++ src/3rdparty/chromium/gpu/command_buffer/service/external_vk_image_backing.h
@@ -154,7 +154,7 @@ class ExternalVkImageBacking final : pub
 
  private:
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Extract file descriptor from image
   int GetMemoryFd(const GrVkImageInfo& image_info);
 #endif
