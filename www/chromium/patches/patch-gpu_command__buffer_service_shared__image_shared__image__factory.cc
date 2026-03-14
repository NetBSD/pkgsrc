$NetBSD: patch-gpu_command__buffer_service_shared__image_shared__image__factory.cc,v 1.16 2026/03/14 12:40:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/shared_image_factory.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ gpu/command_buffer/service/shared_image/shared_image_factory.cc
@@ -52,7 +52,7 @@
 #include "gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.h"
 #include "gpu/vulkan/vulkan_device_queue.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.h"
 #endif
 
@@ -118,7 +118,7 @@ const char* GmbTypeToString(gfx::GpuMemo
     case gfx::IO_SURFACE_BUFFER:
       return "platform";
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case gfx::NATIVE_PIXMAP:
       return "platform";
 #endif
@@ -139,7 +139,7 @@ gfx::GpuMemoryBufferType GetNativeBuffer
   return gfx::GpuMemoryBufferType::IO_SURFACE_BUFFER;
 #elif BUILDFLAG(IS_ANDROID)
   return gfx::GpuMemoryBufferType::ANDROID_HARDWARE_BUFFER;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return gfx::GpuMemoryBufferType::NATIVE_PIXMAP;
 #elif BUILDFLAG(IS_WIN)
   return gfx::GpuMemoryBufferType::DXGI_SHARED_HANDLE;
@@ -314,7 +314,7 @@ SharedImageFactory::SharedImageFactory(
     factories_.push_back(std::move(ozone_factory));
   }
 
-#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA))
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD))
   if (gr_context_type_ == GrContextType::kVulkan
 #if BUILDFLAG(USE_WEBGPU_ON_VULKAN_VIA_GL_INTEROP)
       /* We support GL context for WebGPU gl-vulkan interop (on linux).*/
@@ -1045,7 +1045,7 @@ void SharedImageFactory::LogGetFactoryFa
   }
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // VizBufferQueue with Vulkan enabled over command-line for Linux does not
   // work. Suppress dumps for these cases.
   if (context_state_->GrContextIsVulkan() &&
