$NetBSD: patch-media_video_fake__gpu__memory__buffer.cc,v 1.1 2025/02/06 09:58:13 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/video/fake_gpu_memory_buffer.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/video/fake_gpu_memory_buffer.cc
@@ -14,7 +14,7 @@
 #include "media/base/format_utils.h"
 #include "media/base/video_frame.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -63,7 +63,7 @@ class FakeGpuMemoryBufferImpl : public g
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 base::ScopedFD GetDummyFD() {
   base::ScopedFD fd(open("/dev/zero", O_RDWR));
   DCHECK(fd.is_valid());
@@ -102,7 +102,7 @@ FakeGpuMemoryBuffer::FakeGpuMemoryBuffer
   static base::AtomicSequenceNumber buffer_id_generator;
   handle_.id = gfx::GpuMemoryBufferId(buffer_id_generator.GetNext());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   for (size_t i = 0; i < VideoFrame::NumPlanes(video_pixel_format_); i++) {
     const gfx::Size plane_size_in_bytes =
         VideoFrame::PlaneSize(video_pixel_format_, i, size_);
@@ -176,7 +176,7 @@ gfx::GpuMemoryBufferHandle FakeGpuMemory
   gfx::GpuMemoryBufferHandle handle;
   handle.type = gfx::NATIVE_PIXMAP;
   handle.id = handle_.id;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   handle.native_pixmap_handle =
       gfx::CloneHandleForIPC(handle_.native_pixmap_handle);
 #endif
