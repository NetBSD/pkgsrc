$NetBSD: patch-ui_gfx_mojom_buffer__types__mojom__traits.cc,v 1.1 2025/02/06 09:58:32 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/mojom/buffer_types_mojom_traits.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/gfx/mojom/buffer_types_mojom_traits.cc
@@ -33,7 +33,7 @@ gfx::mojom::GpuMemoryBufferPlatformHandl
       return gfx::mojom::GpuMemoryBufferPlatformHandle::NewSharedMemoryHandle(
           std::move(handle.region));
     case gfx::NATIVE_PIXMAP:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
       return gfx::mojom::GpuMemoryBufferPlatformHandle::NewNativePixmapHandle(
           std::move(handle.native_pixmap_handle));
 #else
@@ -115,7 +115,7 @@ bool StructTraits<gfx::mojom::GpuMemoryB
       out->type = gfx::SHARED_MEMORY_BUFFER;
       out->region = std::move(platform_handle->get_shared_memory_handle());
       return true;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
     case gfx::mojom::GpuMemoryBufferPlatformHandleDataView::Tag::
         kNativePixmapHandle:
       out->type = gfx::NATIVE_PIXMAP;
