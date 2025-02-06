$NetBSD: patch-gpu_ipc_common_gpu__memory__buffer__support.cc,v 1.1 2025/02/06 09:58:10 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/ipc/common/gpu_memory_buffer_support.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ gpu/ipc/common/gpu_memory_buffer_support.cc
@@ -26,7 +26,7 @@
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
-#if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "gpu/ipc/common/gpu_memory_buffer_impl_native_pixmap.h"
 #endif
 
@@ -55,7 +55,7 @@ GpuMemoryBufferSupport::GetNativeGpuMemo
   return gfx::IO_SURFACE_BUFFER;
 #elif BUILDFLAG(IS_ANDROID)
   return gfx::ANDROID_HARDWARE_BUFFER;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
   return gfx::NATIVE_PIXMAP;
 #elif BUILDFLAG(IS_WIN)
   return gfx::DXGI_SHARED_HANDLE;
