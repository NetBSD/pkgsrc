$NetBSD: patch-src_3rdparty_chromium_ui_gfx_gpu__memory__buffer.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/gfx/gpu_memory_buffer.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/gpu_memory_buffer.h
@@ -15,7 +15,7 @@
 #include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/gfx_export.h"
 
-#if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #elif defined(OS_MAC)
 #include "ui/gfx/mac/io_surface.h"
@@ -69,7 +69,7 @@ struct GFX_EXPORT GpuMemoryBufferHandle 
   base::UnsafeSharedMemoryRegion region;
   uint32_t offset = 0;
   int32_t stride = 0;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   NativePixmapHandle native_pixmap_handle;
 #elif defined(OS_MAC)
   ScopedRefCountedIOSurfaceMachPort mach_port;
