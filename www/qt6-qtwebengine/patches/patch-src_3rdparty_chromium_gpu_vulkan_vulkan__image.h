$NetBSD: patch-src_3rdparty_chromium_gpu_vulkan_vulkan__image.h,v 1.1 2025/12/21 09:38:30 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/vulkan/vulkan_image.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/gpu/vulkan/vulkan_image.h
@@ -87,7 +87,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanIma
       VkImageUsageFlags usage,
       VkImageCreateFlags flags);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static std::unique_ptr<VulkanImage> CreateWithExternalMemoryAndModifiers(
       VulkanDeviceQueue* device_queue,
       const gfx::Size& size,
@@ -199,7 +199,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanIma
       VkImageTiling image_tiling,
       uint32_t queue_family_index);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool InitializeWithExternalMemoryAndModifiers(VulkanDeviceQueue* device_queue,
                                                 const gfx::Size& size,
                                                 VkFormat format,
