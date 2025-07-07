$NetBSD: patch-ui_gfx_gpu__memory__buffer.h,v 1.3 2025/07/07 09:23:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/gpu_memory_buffer.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ ui/gfx/gpu_memory_buffer.h
@@ -17,7 +17,7 @@
 #include "ui/gfx/generic_shared_memory_id.h"
 #include "ui/gfx/geometry/rect.h"
 
-#if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #elif BUILDFLAG(IS_APPLE)
 #include "ui/gfx/mac/io_surface.h"
@@ -58,7 +58,7 @@ enum GpuMemoryBufferType {
 #if BUILDFLAG(IS_APPLE)
   IO_SURFACE_BUFFER,
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   NATIVE_PIXMAP,
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -154,7 +154,7 @@ struct COMPONENT_EXPORT(GFX) GpuMemoryBu
 #if BUILDFLAG(IS_WIN)
   explicit GpuMemoryBufferHandle(DXGIHandle handle);
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   explicit GpuMemoryBufferHandle(gfx::NativePixmapHandle native_pixmap_handle);
 #endif
 #if BUILDFLAG(IS_ANDROID)
@@ -196,7 +196,7 @@ struct COMPONENT_EXPORT(GFX) GpuMemoryBu
     return std::move(region_);
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   const NativePixmapHandle& native_pixmap_handle() const& {
     CHECK_EQ(type, NATIVE_PIXMAP);
     return native_pixmap_handle_;
@@ -240,7 +240,7 @@ struct COMPONENT_EXPORT(GFX) GpuMemoryBu
   // goal is to make `this` an encapsulated class.
   base::UnsafeSharedMemoryRegion region_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   NativePixmapHandle native_pixmap_handle_;
 #endif
 
