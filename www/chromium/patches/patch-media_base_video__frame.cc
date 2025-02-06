$NetBSD: patch-media_base_video__frame.cc,v 1.1 2025/02/06 09:58:12 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/base/video_frame.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/base/video_frame.cc
@@ -88,7 +88,7 @@ std::string VideoFrame::StorageTypeToStr
       return "OWNED_MEMORY";
     case VideoFrame::STORAGE_SHMEM:
       return "SHMEM";
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case VideoFrame::STORAGE_DMABUFS:
       return "DMABUFS";
 #endif
@@ -103,7 +103,7 @@ std::string VideoFrame::StorageTypeToStr
 // static
 bool VideoFrame::IsStorageTypeMappable(VideoFrame::StorageType storage_type) {
   return
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // This is not strictly needed but makes explicit that, at VideoFrame
       // level, DmaBufs are not mappable from userspace.
       storage_type != VideoFrame::STORAGE_DMABUFS &&
@@ -401,7 +401,7 @@ VideoFrame::CreateFrameForGpuMemoryBuffe
                            : shared_image->GetStrideForVideoFrame(i);
   }
   uint64_t modifier = gfx::NativePixmapHandle::kNoModifier;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool is_native_buffer =
       gpu_memory_buffer
           ? (gpu_memory_buffer->GetType() != gfx::SHARED_MEMORY_BUFFER)
@@ -453,7 +453,7 @@ VideoFrame::CreateFrameForGpuMemoryBuffe
 }
 
 // static
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 scoped_refptr<VideoFrame> VideoFrame::WrapOOPVDMailbox(
     VideoPixelFormat format,
     const gpu::Mailbox& mailbox,
@@ -769,7 +769,7 @@ scoped_refptr<VideoFrame> VideoFrame::Wr
   return frame;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 scoped_refptr<VideoFrame> VideoFrame::WrapExternalDmabufs(
     const VideoFrameLayout& layout,
@@ -1261,7 +1261,7 @@ bool VideoFrame::IsMappable() const {
   return IsStorageTypeMappable(storage_type_);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
 bool VideoFrame::HasOOPVDMailbox() const {
   return wrapped_frame_ ? wrapped_frame_->HasOOPVDMailbox()
                         : !oopvd_mailbox_.IsZero();
@@ -1490,7 +1490,7 @@ scoped_refptr<gpu::ClientSharedImage> Vi
   return wrapped_frame_ ? wrapped_frame_->shared_image() : shared_image_;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 size_t VideoFrame::NumDmabufFds() const {
   if (wrapped_frame_) {
     return wrapped_frame_->NumDmabufFds();
