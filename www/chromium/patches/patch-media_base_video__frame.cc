$NetBSD: patch-media_base_video__frame.cc,v 1.33 2026/11/19 19:46:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/base/video_frame.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ media/base/video_frame.cc
@@ -90,7 +90,7 @@ std::string VideoFrame::StorageTypeToStr
       return "OWNED_MEMORY";
     case VideoFrame::STORAGE_SHMEM:
       return "SHMEM";
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case VideoFrame::STORAGE_DMABUFS:
       return "DMABUFS";
 #endif
@@ -515,7 +515,7 @@ scoped_refptr<VideoFrame> VideoFrame::Wr
         plane_size.width() * VideoFrame::BytesPerElement(*format, plane);
   }
   uint64_t modifier = gfx::NativePixmapHandle::kNoModifier;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (shared_image->GetGpuMemoryBufferType() ==
       gfx::GpuMemoryBufferType::NATIVE_PIXMAP) {
     const auto gmb_handle = shared_image->CloneGpuMemoryBufferHandle();
@@ -780,7 +780,7 @@ scoped_refptr<VideoFrame> VideoFrame::Wr
   return frame;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 scoped_refptr<VideoFrame> VideoFrame::WrapExternalDmabufs(
     const VideoFrameLayout& layout,
@@ -1515,7 +1515,7 @@ scoped_refptr<gpu::ClientSharedImage> Vi
   return wrapped_frame_ ? wrapped_frame_->shared_image() : shared_image_;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 size_t VideoFrame::NumDmabufFds() const {
   if (wrapped_frame_) {
     return wrapped_frame_->NumDmabufFds();
