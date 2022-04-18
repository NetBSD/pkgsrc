$NetBSD: patch-src_3rdparty_chromium_media_capture_video_file__video__capture__device__factory.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/media/capture/video/file_video_capture_device_factory.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/file_video_capture_device_factory.cc
@@ -52,7 +52,7 @@ void FileVideoCaptureDeviceFactory::GetD
       VideoCaptureApi::WIN_DIRECT_SHOW;
 #elif defined(OS_MAC)
       VideoCaptureApi::MACOSX_AVFOUNDATION;
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE;
 #else
       VideoCaptureApi::UNKNOWN;
