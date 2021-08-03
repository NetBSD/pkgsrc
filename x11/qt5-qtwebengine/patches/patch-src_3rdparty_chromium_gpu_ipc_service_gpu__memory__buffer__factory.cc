$NetBSD: patch-src_3rdparty_chromium_gpu_ipc_service_gpu__memory__buffer__factory.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/gpu/ipc/service/gpu_memory_buffer_factory.cc.orig	2020-07-08 21:40:44.000000000 +0000
+++ src/3rdparty/chromium/gpu/ipc/service/gpu_memory_buffer_factory.cc
@@ -12,7 +12,7 @@
 #include "gpu/ipc/service/gpu_memory_buffer_factory_io_surface.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 #include "gpu/ipc/service/gpu_memory_buffer_factory_native_pixmap.h"
 #endif
 
@@ -34,7 +34,7 @@ GpuMemoryBufferFactory::CreateNativeType
   return std::make_unique<GpuMemoryBufferFactoryIOSurface>();
 #elif defined(OS_ANDROID)
   return std::make_unique<GpuMemoryBufferFactoryAndroidHardwareBuffer>();
-#elif defined(OS_LINUX) || defined(OS_FUCHSIA)
+#elif defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return std::make_unique<GpuMemoryBufferFactoryNativePixmap>(
       vulkan_context_provider);
 #elif defined(OS_WIN)
