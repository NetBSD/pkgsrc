$NetBSD: patch-src_3rdparty_chromium_media_capture_video_file__video__capture__device__factory.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/media/capture/video/file_video_capture_device_factory.cc.orig	2020-07-08 21:40:45.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/file_video_capture_device_factory.cc
@@ -54,7 +54,7 @@ void FileVideoCaptureDeviceFactory::GetD
 #elif defined(OS_MACOSX)
       command_line_file_path.value(), kFileVideoCaptureDeviceName,
       VideoCaptureApi::MACOSX_AVFOUNDATION
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
       command_line_file_path.value(), kFileVideoCaptureDeviceName,
       VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE
 #else
