$NetBSD: patch-src_3rdparty_chromium_gpu_ipc_common_gpu__memory__buffer__support.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/gpu/ipc/common/gpu_memory_buffer_support.h.orig	2020-07-08 21:40:44.000000000 +0000
+++ src/3rdparty/chromium/gpu/ipc/common/gpu_memory_buffer_support.h
@@ -16,7 +16,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(USE_OZONE) || defined(OS_BSD)
 namespace gfx {
 class ClientNativePixmapFactory;
 }
@@ -38,7 +38,7 @@ class GPU_EXPORT GpuMemoryBufferSupport 
   bool IsNativeGpuMemoryBufferConfigurationSupported(gfx::BufferFormat format,
                                                      gfx::BufferUsage usage);
 
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(USE_OZONE) || defined(OS_BSD)
   gfx::ClientNativePixmapFactory* client_native_pixmap_factory() {
     return client_native_pixmap_factory_.get();
   }
@@ -62,7 +62,7 @@ class GPU_EXPORT GpuMemoryBufferSupport 
       GpuMemoryBufferImpl::DestructionCallback callback);
 
  private:
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(USE_OZONE) || defined(OS_BSD)
   std::unique_ptr<gfx::ClientNativePixmapFactory> client_native_pixmap_factory_;
 #endif
 
