$NetBSD: patch-ui_gfx_gpu__memory__buffer.h,v 1.1 2025/02/06 09:58:32 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/gpu_memory_buffer.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/gfx/gpu_memory_buffer.h
@@ -15,7 +15,7 @@
 #include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/gfx_export.h"
 
-#if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #elif BUILDFLAG(IS_APPLE)
 #include "ui/gfx/mac/io_surface.h"
@@ -76,7 +76,7 @@ struct GFX_EXPORT GpuMemoryBufferHandle 
   base::UnsafeSharedMemoryRegion region;
   uint32_t offset = 0;
   uint32_t stride = 0;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   NativePixmapHandle native_pixmap_handle;
 #elif BUILDFLAG(IS_APPLE)
   ScopedIOSurface io_surface;
