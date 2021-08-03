$NetBSD: patch-src_3rdparty_chromium_services_video__capture_broadcasting__receiver.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/services/video_capture/broadcasting_receiver.cc.orig	2020-07-15 18:56:01.000000000 +0000
+++ src/3rdparty/chromium/services/video_capture/broadcasting_receiver.cc
@@ -39,7 +39,7 @@ void CloneSharedBufferHandle(const mojo:
 void CloneSharedBufferToRawFileDescriptorHandle(
     const mojo::ScopedSharedBufferHandle& source,
     media::mojom::VideoBufferHandlePtr* target) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // |source| is unwrapped to a |PlatformSharedMemoryRegion|, from whence a file
   // descriptor can be extracted which is then mojo-wrapped.
   base::subtle::PlatformSharedMemoryRegion platform_region =
@@ -182,7 +182,7 @@ void BroadcastingReceiver::BufferContext
     ConvertRawFileDescriptorToSharedBuffer() {
   DCHECK(buffer_handle_->is_shared_memory_via_raw_file_descriptor());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // The conversion unwraps the descriptor from its mojo handle to the raw file
   // descriptor (ie, an int). This is used to create a
   // PlatformSharedMemoryRegion which is then wrapped as a
