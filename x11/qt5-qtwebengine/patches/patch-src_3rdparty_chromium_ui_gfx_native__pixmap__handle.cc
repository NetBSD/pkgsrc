$NetBSD: patch-src_3rdparty_chromium_ui_gfx_native__pixmap__handle.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/gfx/native_pixmap_handle.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/native_pixmap_handle.cc
@@ -8,13 +8,17 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
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
@@ -22,7 +26,7 @@
 
 namespace gfx {
 
-#if defined(OS_LINUX)&& !defined(TOOLKIT_QT)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(TOOLKIT_QT)
 static_assert(NativePixmapHandle::kNoModifier == DRM_FORMAT_MOD_INVALID,
               "gfx::NativePixmapHandle::kNoModifier should be an alias for"
               "DRM_FORMAT_MOD_INVALID");
@@ -33,7 +37,7 @@ NativePixmapPlane::NativePixmapPlane() :
 NativePixmapPlane::NativePixmapPlane(int stride,
                                      int offset,
                                      uint64_t size
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                                      ,
                                      base::ScopedFD fd
 #elif defined(OS_FUCHSIA)
@@ -44,7 +48,7 @@ NativePixmapPlane::NativePixmapPlane(int
     : stride(stride),
       offset(offset),
       size(size)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       ,
       fd(std::move(fd))
 #elif defined(OS_FUCHSIA)
@@ -72,7 +76,7 @@ NativePixmapHandle& NativePixmapHandle::
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   for (auto& plane : handle.planes) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     DCHECK(plane.fd.is_valid());
     base::ScopedFD fd_dup(HANDLE_EINTR(dup(plane.fd.get())));
     if (!fd_dup.is_valid()) {
@@ -98,7 +102,7 @@ NativePixmapHandle CloneHandleForIPC(con
 #endif
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   clone.modifier = handle.modifier;
 #endif
 
