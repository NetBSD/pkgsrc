$NetBSD: patch-src_3rdparty_chromium_media_mojo_clients_mojo__video__encode__accelerator.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/media/mojo/clients/mojo_video_encode_accelerator.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/media/mojo/clients/mojo_video_encode_accelerator.cc
@@ -134,7 +134,7 @@ void MojoVideoEncodeAccelerator::Encode(
   DCHECK_EQ(num_planes, frame->layout().num_planes());
   DCHECK(vea_.is_bound());
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // TODO(crbug.com/1003197): Remove this once we stop supporting STORAGE_DMABUF
   // in VideoEncodeAccelerator.
   if (frame->storage_type() == VideoFrame::STORAGE_DMABUFS) {
