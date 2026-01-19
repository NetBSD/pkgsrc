$NetBSD: patch-media_capture_video_fake__video__capture__device__factory.cc,v 1.14 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/capture/video/fake_video_capture_device_factory.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ media/capture/video/fake_video_capture_device_factory.cc
@@ -228,7 +228,7 @@ void FakeVideoCaptureDeviceFactory::GetD
   int entry_index = 0;
   for (const auto& entry : devices_config_) {
     VideoCaptureApi api =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE;
 #elif BUILDFLAG(IS_IOS)
         VideoCaptureApi::UNKNOWN;
