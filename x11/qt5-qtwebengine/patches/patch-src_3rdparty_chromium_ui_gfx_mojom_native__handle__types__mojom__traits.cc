$NetBSD: patch-src_3rdparty_chromium_ui_gfx_mojom_native__handle__types__mojom__traits.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/gfx/mojom/native_handle_types_mojom_traits.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/mojom/native_handle_types_mojom_traits.cc
@@ -8,11 +8,11 @@
 
 namespace mojo {
 
-#if defined(OS_LINUX) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(USE_OZONE) || defined(OS_BSD)
 mojo::PlatformHandle StructTraits<
     gfx::mojom::NativePixmapPlaneDataView,
     gfx::NativePixmapPlane>::buffer_handle(gfx::NativePixmapPlane& plane) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return mojo::PlatformHandle(std::move(plane.fd));
 #elif defined(OS_FUCHSIA)
   return mojo::PlatformHandle(std::move(plane.vmo));
@@ -28,7 +28,7 @@ bool StructTraits<
   out->size = data.size();
 
   mojo::PlatformHandle handle = data.TakeBufferHandle();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!handle.is_fd())
     return false;
   out->fd = handle.TakeFD();
@@ -45,7 +45,7 @@ bool StructTraits<
     gfx::mojom::NativePixmapHandleDataView,
     gfx::NativePixmapHandle>::Read(gfx::mojom::NativePixmapHandleDataView data,
                                    gfx::NativePixmapHandle* out) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   out->modifier = data.modifier();
 #endif
 
