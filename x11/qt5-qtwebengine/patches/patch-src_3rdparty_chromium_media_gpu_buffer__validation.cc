$NetBSD: patch-src_3rdparty_chromium_media_gpu_buffer__validation.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/media/gpu/buffer_validation.cc.orig	2020-07-08 21:40:45.000000000 +0000
+++ src/3rdparty/chromium/media/gpu/buffer_validation.cc
@@ -12,7 +12,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/types.h>
 #include <unistd.h>
 #endif  // defined(OS_LINUX)
@@ -20,7 +20,7 @@
 namespace media {
 
 bool GetFileSize(const int fd, size_t* size) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (fd < 0) {
     VLOGF(1) << "Invalid file descriptor";
     return false;
@@ -56,7 +56,7 @@ bool VerifyGpuMemoryBufferHandle(media::
     VLOGF(1) << "Unexpected GpuMemoryBufferType: " << gmb_handle.type;
     return false;
   }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const size_t num_planes = media::VideoFrame::NumPlanes(pixel_format);
   if (num_planes != gmb_handle.native_pixmap_handle.planes.size() ||
       num_planes == 0) {
