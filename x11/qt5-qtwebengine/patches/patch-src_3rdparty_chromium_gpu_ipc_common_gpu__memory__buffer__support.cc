$NetBSD: patch-src_3rdparty_chromium_gpu_ipc_common_gpu__memory__buffer__support.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/gpu/ipc/common/gpu_memory_buffer_support.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/gpu/ipc/common/gpu_memory_buffer_support.cc
@@ -14,7 +14,7 @@
 #include "gpu/ipc/common/gpu_memory_buffer_impl_io_surface.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/client_native_pixmap_factory.h"
 #include "ui/gfx/linux/client_native_pixmap_factory_dmabuf.h"
 #endif
@@ -24,7 +24,7 @@
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
-#if defined(USE_OZONE) || defined(OS_LINUX)
+#if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_BSD)
 #include "gpu/ipc/common/gpu_memory_buffer_impl_native_pixmap.h"
 #endif
 
@@ -42,7 +42,7 @@ namespace gpu {
 GpuMemoryBufferSupport::GpuMemoryBufferSupport() {
 #if defined(USE_OZONE)
   client_native_pixmap_factory_ = ui::CreateClientNativePixmapFactoryOzone();
-#elif defined(OS_LINUX) && !defined(TOOLKIT_QT)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(TOOLKIT_QT)
   client_native_pixmap_factory_.reset(
       gfx::CreateClientNativePixmapFactoryDmabuf());
 #endif
@@ -56,7 +56,7 @@ GpuMemoryBufferSupport::GetNativeGpuMemo
   return gfx::IO_SURFACE_BUFFER;
 #elif defined(OS_ANDROID)
   return gfx::ANDROID_HARDWARE_BUFFER;
-#elif (defined(OS_LINUX) || defined(USE_OZONE)) && !defined(TOOLKIT_QT)
+#elif (defined(OS_LINUX) || defined(USE_OZONE) || defined(OS_BSD)) && !defined(TOOLKIT_QT)
   return gfx::NATIVE_PIXMAP;
 #elif defined(OS_WIN)
   return gfx::DXGI_SHARED_HANDLE;
@@ -181,7 +181,7 @@ GpuMemoryBufferSupport::CreateGpuMemoryB
       return GpuMemoryBufferImplIOSurface::CreateFromHandle(
           std::move(handle), size, format, usage, std::move(callback));
 #endif
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(USE_OZONE) || defined(OS_BSD)
     case gfx::NATIVE_PIXMAP:
       return GpuMemoryBufferImplNativePixmap::CreateFromHandle(
           client_native_pixmap_factory(), std::move(handle), size, format,
