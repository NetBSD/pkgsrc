$NetBSD: patch-src_3rdparty_chromium_ui_gfx_mojom_native__handle__types__mojom__traits.cc,v 1.1 2025/12/21 09:38:48 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/gfx/mojom/native_handle_types_mojom_traits.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/mojom/native_handle_types_mojom_traits.cc
@@ -14,7 +14,7 @@
 #include "ui/gfx/mac/io_surface.h"
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
 
@@ -80,11 +80,11 @@ bool StructTraits<gfx::mojom::AHardwareB
 }
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
 mojo::PlatformHandle StructTraits<
     gfx::mojom::NativePixmapPlaneDataView,
     gfx::NativePixmapPlane>::buffer_handle(gfx::NativePixmapPlane& plane) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return mojo::PlatformHandle(std::move(plane.fd));
 #elif BUILDFLAG(IS_FUCHSIA)
   return mojo::PlatformHandle(std::move(plane.vmo));
@@ -100,7 +100,7 @@ bool StructTraits<
   out->size = data.size();
 
   mojo::PlatformHandle handle = data.TakeBufferHandle();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!handle.is_fd())
     return false;
   out->fd = handle.TakeFD();
@@ -126,7 +126,7 @@ bool StructTraits<
     gfx::mojom::NativePixmapHandleDataView,
     gfx::NativePixmapHandle>::Read(gfx::mojom::NativePixmapHandleDataView data,
                                    gfx::NativePixmapHandle* out) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   out->modifier = data.modifier();
   out->supports_zero_copy_webgpu_import =
       data.supports_zero_copy_webgpu_import();
@@ -190,7 +190,7 @@ gfx::mojom::GpuMemoryBufferPlatformHandl
       NOTREACHED();
 #endif  // BUILDFLAG(IS_APPLE)
     case gfx::NATIVE_PIXMAP:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
       return Tag::kNativePixmapHandle;
 #else
       NOTREACHED();
@@ -259,7 +259,7 @@ bool UnionTraits<gfx::mojom::GpuMemoryBu
       }
       return true;
 #endif  // BUILDFLAG(IS_APPLE)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
     case Tag::kNativePixmapHandle:
       handle->type = gfx::NATIVE_PIXMAP;
       return data.ReadNativePixmapHandle(&handle->native_pixmap_handle);
