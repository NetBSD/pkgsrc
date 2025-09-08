$NetBSD: patch-media_base_video__frame.cc,v 1.6 2025/09/08 13:24:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/base/video_frame.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ media/base/video_frame.cc
@@ -87,7 +87,7 @@ std::string VideoFrame::StorageTypeToStr
       return "OWNED_MEMORY";
     case VideoFrame::STORAGE_SHMEM:
       return "SHMEM";
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case VideoFrame::STORAGE_DMABUFS:
       return "DMABUFS";
 #endif
@@ -101,7 +101,7 @@ std::string VideoFrame::StorageTypeToStr
 // static
 bool VideoFrame::IsStorageTypeMappable(VideoFrame::StorageType storage_type) {
   return
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // This is not strictly needed but makes explicit that, at VideoFrame
       // level, DmaBufs are not mappable from userspace.
       storage_type != VideoFrame::STORAGE_DMABUFS &&
@@ -396,7 +396,7 @@ scoped_refptr<VideoFrame> VideoFrame::Cr
         plane_size.width() * VideoFrame::BytesPerElement(*format, plane);
   }
   uint64_t modifier = gfx::NativePixmapHandle::kNoModifier;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool is_native_buffer = !shared_image->IsSharedMemoryForVideoFrame();
   if (is_native_buffer) {
     const auto gmb_handle = shared_image->CloneGpuMemoryBufferHandle();
@@ -861,7 +861,7 @@ scoped_refptr<VideoFrame> VideoFrame::Wr
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 scoped_refptr<VideoFrame> VideoFrame::WrapExternalDmabufs(
     const VideoFrameLayout& layout,
@@ -1535,7 +1535,7 @@ scoped_refptr<gpu::ClientSharedImage> Vi
   return wrapped_frame_ ? wrapped_frame_->shared_image() : shared_image_;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 size_t VideoFrame::NumDmabufFds() const {
   if (wrapped_frame_) {
     return wrapped_frame_->NumDmabufFds();
