$NetBSD: patch-gpu_command__buffer_service_shared__image_gpu__memory__buffer__factory.cc,v 1.1 2025/11/04 14:55:41 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/gpu_memory_buffer_factory.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ gpu/command_buffer/service/shared_image/gpu_memory_buffer_factory.cc
@@ -14,7 +14,7 @@
 #include "gpu/command_buffer/service/shared_image/gpu_memory_buffer_factory_io_surface.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "gpu/command_buffer/service/shared_image/gpu_memory_buffer_factory_native_pixmap.h"
 #endif
 
@@ -36,7 +36,7 @@ GpuMemoryBufferFactory::CreateNativeType
   // AHardwareBuffers), but the codebase is structured such that it is easier
   // to create a dummy factory than create no factory.
   return std::make_unique<GpuMemoryBufferFactory>();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return std::make_unique<GpuMemoryBufferFactoryNativePixmap>(
       vulkan_context_provider);
 #elif BUILDFLAG(IS_WIN)
