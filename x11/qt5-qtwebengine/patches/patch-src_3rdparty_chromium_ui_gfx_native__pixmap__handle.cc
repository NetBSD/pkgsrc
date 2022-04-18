$NetBSD: patch-src_3rdparty_chromium_ui_gfx_native__pixmap__handle.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/gfx/native_pixmap_handle.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/native_pixmap_handle.cc
@@ -9,13 +9,17 @@
 #include "base/logging.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if !defined(TOOLKIT_QT)
 #include <drm_fourcc.h>
 #endif
 #include "base/posix/eintr_wrapper.h"
 #endif
 
+#if defined(OS_BSD)
+#include <unistd.h>
+#endif
+
 #if defined(OS_FUCHSIA)
 #include <lib/zx/vmo.h>
 #include "base/fuchsia/fuchsia_logging.h"
@@ -23,7 +27,7 @@
 
 namespace gfx {
 
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(TOOLKIT_QT)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && !defined(TOOLKIT_QT)
 static_assert(NativePixmapHandle::kNoModifier == DRM_FORMAT_MOD_INVALID,
               "gfx::NativePixmapHandle::kNoModifier should be an alias for"
               "DRM_FORMAT_MOD_INVALID");
@@ -34,7 +38,7 @@ NativePixmapPlane::NativePixmapPlane() :
 NativePixmapPlane::NativePixmapPlane(int stride,
                                      int offset,
                                      uint64_t size
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
                                      ,
                                      base::ScopedFD fd
 #elif defined(OS_FUCHSIA)
@@ -45,7 +49,7 @@ NativePixmapPlane::NativePixmapPlane(int
     : stride(stride),
       offset(offset),
       size(size)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       ,
       fd(std::move(fd))
 #elif defined(OS_FUCHSIA)
@@ -73,7 +77,7 @@ NativePixmapHandle& NativePixmapHandle::
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   for (auto& plane : handle.planes) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     DCHECK(plane.fd.is_valid());
     base::ScopedFD fd_dup(HANDLE_EINTR(dup(plane.fd.get())));
     if (!fd_dup.is_valid()) {
@@ -99,7 +103,7 @@ NativePixmapHandle CloneHandleForIPC(con
 #endif
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   clone.modifier = handle.modifier;
 #endif
 
