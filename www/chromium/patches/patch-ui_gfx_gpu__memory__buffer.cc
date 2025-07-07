$NetBSD: patch-ui_gfx_gpu__memory__buffer.cc,v 1.3 2025/07/07 09:23:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/gpu_memory_buffer.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ ui/gfx/gpu_memory_buffer.cc
@@ -100,7 +100,7 @@ GpuMemoryBufferHandle::GpuMemoryBufferHa
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 GpuMemoryBufferHandle::GpuMemoryBufferHandle(
     NativePixmapHandle native_pixmap_handle)
     : type(GpuMemoryBufferType::NATIVE_PIXMAP),
@@ -138,7 +138,7 @@ GpuMemoryBufferHandle GpuMemoryBufferHan
   handle.id = id;
   handle.offset = offset;
   handle.stride = stride;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   handle.native_pixmap_handle_ = CloneHandleForIPC(native_pixmap_handle_);
 #elif BUILDFLAG(IS_APPLE)
   handle.io_surface = io_surface;
