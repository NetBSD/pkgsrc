$NetBSD: patch-src_3rdparty_chromium_media_video_fake__gpu__memory__buffer.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/media/video/fake_gpu_memory_buffer.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/media/video/fake_gpu_memory_buffer.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -44,7 +44,7 @@ class FakeGpuMemoryBufferImpl : public g
 
 }  // namespace
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 base::ScopedFD GetDummyFD() {
   base::ScopedFD fd(open("/dev/zero", O_RDWR));
   DCHECK(fd.is_valid());
@@ -67,7 +67,7 @@ FakeGpuMemoryBuffer::FakeGpuMemoryBuffer
   // Set a dummy id since this is for testing only.
   handle_.id = gfx::GpuMemoryBufferId(0);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Set a dummy fd since this is for testing only.
   handle_.native_pixmap_handle.planes.push_back(
       gfx::NativePixmapPlane(size_.width(), 0, y_plane_size, GetDummyFD()));
@@ -135,7 +135,7 @@ gfx::GpuMemoryBufferHandle FakeGpuMemory
   gfx::GpuMemoryBufferHandle handle;
   handle.type = gfx::NATIVE_PIXMAP;
   handle.id = handle_.id;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   handle.native_pixmap_handle =
       gfx::CloneHandleForIPC(handle_.native_pixmap_handle);
 #endif
