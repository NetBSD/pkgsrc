$NetBSD: patch-src_3rdparty_chromium_media_capture_video_fake__video__capture__device__factory.cc,v 1.1 2025/12/21 09:38:31 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/capture/video/fake_video_capture_device_factory.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/fake_video_capture_device_factory.cc
@@ -231,7 +231,7 @@ void FakeVideoCaptureDeviceFactory::GetD
   int entry_index = 0;
   for (const auto& entry : devices_config_) {
     VideoCaptureApi api =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE;
 #elif BUILDFLAG(IS_IOS)
         VideoCaptureApi::UNKNOWN;
