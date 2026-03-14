$NetBSD: patch-gpu_vulkan_vulkan__image.h,v 1.16 2026/03/14 12:40:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/vulkan/vulkan_image.h.orig	2026-03-11 22:12:25.000000000 +0000
+++ gpu/vulkan/vulkan_image.h
@@ -86,7 +86,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanIma
       VkImageUsageFlags usage,
       VkImageCreateFlags flags);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static std::unique_ptr<VulkanImage> CreateWithExternalMemoryAndModifiers(
       VulkanDeviceQueue* device_queue,
       const gfx::Size& size,
@@ -198,7 +198,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanIma
       VkImageTiling image_tiling,
       uint32_t queue_family_index);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool InitializeWithExternalMemoryAndModifiers(VulkanDeviceQueue* device_queue,
                                                 const gfx::Size& size,
                                                 VkFormat format,
