$NetBSD: patch-src_3rdparty_chromium_gpu_command__buffer_service_shared__image_angle__vulkan__image__backing__factory.cc,v 1.2 2026/04/30 06:39:41 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.cc
@@ -20,7 +20,7 @@ namespace {
 // TODO(penghuang): verify the scanout is the right usage for video playback.
 // crbug.com/1280798
 constexpr SharedImageUsageSet kSupportedUsage =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     SHARED_IMAGE_USAGE_SCANOUT |
 #endif
     SHARED_IMAGE_USAGE_GLES2_READ | SHARED_IMAGE_USAGE_GLES2_WRITE |
@@ -121,7 +121,7 @@ bool AngleVulkanImageBackingFactory::IsG
   switch (gmb_type) {
     case gfx::EMPTY_BUFFER:
       return true;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case gfx::NATIVE_PIXMAP: {
       auto* vulkan_implementation =
           context_state_->vk_context_provider()->GetVulkanImplementation();
