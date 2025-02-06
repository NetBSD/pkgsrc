$NetBSD: patch-ui_gfx_mojom_native__handle__types__mojom__traits.h,v 1.1 2025/02/06 09:58:32 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/mojom/native_handle_types_mojom_traits.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/gfx/mojom/native_handle_types_mojom_traits.h
@@ -16,7 +16,7 @@
 #include "mojo/public/cpp/system/platform_handle.h"
 #include "ui/gfx/mojom/native_handle_types.mojom-shared.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #endif
 
@@ -26,7 +26,7 @@
 
 namespace mojo {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
 template <>
 struct COMPONENT_EXPORT(GFX_NATIVE_HANDLE_TYPES_SHARED_MOJOM_TRAITS)
     StructTraits<gfx::mojom::NativePixmapPlaneDataView,
@@ -54,13 +54,13 @@ struct COMPONENT_EXPORT(GFX_NATIVE_HANDL
     return pixmap_handle.planes;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static uint64_t modifier(const gfx::NativePixmapHandle& pixmap_handle) {
     return pixmap_handle.modifier;
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static bool supports_zero_copy_webgpu_import(
       const gfx::NativePixmapHandle& pixmap_handle) {
     return pixmap_handle.supports_zero_copy_webgpu_import;
