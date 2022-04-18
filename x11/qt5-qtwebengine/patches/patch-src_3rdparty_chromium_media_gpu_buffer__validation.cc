$NetBSD: patch-src_3rdparty_chromium_media_gpu_buffer__validation.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/media/gpu/buffer_validation.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/media/gpu/buffer_validation.cc
@@ -12,7 +12,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/types.h>
 #include <unistd.h>
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
@@ -20,7 +20,7 @@
 namespace media {
 
 bool GetFileSize(const int fd, size_t* size) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (fd < 0) {
     VLOGF(1) << "Invalid file descriptor";
     return false;
@@ -56,7 +56,7 @@ bool VerifyGpuMemoryBufferHandle(media::
     VLOGF(1) << "Unexpected GpuMemoryBufferType: " << gmb_handle.type;
     return false;
   }
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   const size_t num_planes = media::VideoFrame::NumPlanes(pixel_format);
   if (num_planes != gmb_handle.native_pixmap_handle.planes.size() ||
       num_planes == 0) {
