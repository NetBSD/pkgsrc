$NetBSD: patch-src_3rdparty_chromium_ui_ozone_platform_headless_vulkan__implementation__headless.cc,v 1.2 2026/04/30 06:39:45 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/ozone/platform/headless/vulkan_implementation_headless.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/ui/ozone/platform/headless/vulkan_implementation_headless.cc
@@ -117,7 +117,7 @@ VulkanImplementationHeadless::ExportVkFe
 
 VkExternalSemaphoreHandleTypeFlagBits
 VulkanImplementationHeadless::GetExternalSemaphoreHandleType() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT;
 #else
   return VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT;
@@ -127,7 +127,7 @@ VulkanImplementationHeadless::GetExterna
 bool VulkanImplementationHeadless::CanImportGpuMemoryBuffer(
     gpu::VulkanDeviceQueue* device_queue,
     gfx::GpuMemoryBufferType memory_buffer_type) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const auto& enabled_extensions = device_queue->enabled_extensions();
   return gfx::HasExtension(enabled_extensions,
                            VK_EXT_EXTERNAL_MEMORY_DMA_BUF_EXTENSION_NAME) &&
@@ -150,7 +150,7 @@ VulkanImplementationHeadless::CreateImag
       VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_SAMPLED_BIT |
       VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
   auto tiling = VK_IMAGE_TILING_OPTIMAL;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (gmb_handle.native_pixmap_handle().modifier !=
       gfx::NativePixmapHandle::kNoModifier) {
     tiling = VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT;
