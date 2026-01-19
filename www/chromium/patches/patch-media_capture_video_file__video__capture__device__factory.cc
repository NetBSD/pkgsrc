$NetBSD: patch-media_capture_video_file__video__capture__device__factory.cc,v 1.14 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/capture/video/file_video_capture_device_factory.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ media/capture/video/file_video_capture_device_factory.cc
@@ -52,7 +52,7 @@ void FileVideoCaptureDeviceFactory::GetD
       VideoCaptureApi::WIN_DIRECT_SHOW;
 #elif BUILDFLAG(IS_MAC)
       VideoCaptureApi::MACOSX_AVFOUNDATION;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE;
 #else
       VideoCaptureApi::UNKNOWN;
