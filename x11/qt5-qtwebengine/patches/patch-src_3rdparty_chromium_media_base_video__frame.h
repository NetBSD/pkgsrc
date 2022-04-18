$NetBSD: patch-src_3rdparty_chromium_media_base_video__frame.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/media/base/video_frame.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/media/base/video_frame.h
@@ -41,7 +41,7 @@
 #include "base/mac/scoped_cftyperef.h"
 #endif  // defined(OS_MAC)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/files/scoped_file.h"
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
 
@@ -83,7 +83,7 @@ class MEDIA_EXPORT VideoFrame : public b
     STORAGE_UNOWNED_MEMORY = 2,  // External, non owned data pointers.
     STORAGE_OWNED_MEMORY = 3,  // VideoFrame has allocated its own data buffer.
     STORAGE_SHMEM = 4,         // Backed by unsafe (writable) shared memory.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // TODO(mcasas): Consider turning this type into STORAGE_NATIVE
     // based on the idea of using this same enum value for both DMA
     // buffers on Linux and CVPixelBuffers on Mac (which currently use
@@ -260,7 +260,7 @@ class MEDIA_EXPORT VideoFrame : public b
       ReleaseMailboxCB mailbox_holder_release_cb,
       base::TimeDelta timestamp);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Wraps provided dmabufs
   // (https://www.kernel.org/doc/html/latest/driver-api/dma-buf.html) with a
   // VideoFrame. The frame will take ownership of |dmabuf_fds|, and will
@@ -507,7 +507,7 @@ class MEDIA_EXPORT VideoFrame : public b
   // mailbox, the caller must wait for the included sync point.
   const gpu::MailboxHolder& mailbox_holder(size_t texture_index) const;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Returns a vector containing the backing DmaBufs for this frame. The number
   // of returned DmaBufs will be equal or less than the number of planes of
   // the frame. If there are less, this means that the last FD contains the
@@ -696,7 +696,7 @@ class MEDIA_EXPORT VideoFrame : public b
   // GPU memory buffer, if this frame is STORAGE_GPU_MEMORY_BUFFER.
   std::unique_ptr<gfx::GpuMemoryBuffer> gpu_memory_buffer_;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   class DmabufHolder;
 
   // Dmabufs for the frame, used when storage is STORAGE_DMABUFS. Size is either
