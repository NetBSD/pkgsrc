$NetBSD: patch-gpu_ipc_service_gpu__memory__buffer__factory.cc,v 1.7 2025/09/12 16:02:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/ipc/service/gpu_memory_buffer_factory.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ gpu/ipc/service/gpu_memory_buffer_factory.cc
@@ -14,7 +14,7 @@
 #include "gpu/ipc/service/gpu_memory_buffer_factory_io_surface.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "gpu/ipc/service/gpu_memory_buffer_factory_native_pixmap.h"
 #endif
 
@@ -65,7 +65,7 @@ GpuMemoryBufferFactory::CreateNativeType
   // to have a factory that vends invalid GMB handles rather than having no
   // factory at all.
   return std::make_unique<GpuMemoryBufferFactoryStub>();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return std::make_unique<GpuMemoryBufferFactoryNativePixmap>(
       vulkan_context_provider);
 #elif BUILDFLAG(IS_WIN)
