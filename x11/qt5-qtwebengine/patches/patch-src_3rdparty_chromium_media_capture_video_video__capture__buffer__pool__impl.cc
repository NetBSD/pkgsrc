$NetBSD: patch-src_3rdparty_chromium_media_capture_video_video__capture__buffer__pool__impl.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/media/capture/video/video_capture_buffer_pool_impl.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/video_capture_buffer_pool_impl.cc
@@ -58,7 +58,7 @@ VideoCaptureBufferPoolImpl::CreateShared
     int buffer_id) {
 // This requires platforms where base::SharedMemoryHandle is backed by a
 // file descriptor.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   base::AutoLock lock(lock_);
 
   VideoCaptureBufferTracker* tracker = GetTracker(buffer_id);
