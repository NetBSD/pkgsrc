$NetBSD: patch-src_3rdparty_chromium_media_capture_video_fake__video__capture__device__factory.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/media/capture/video/fake_video_capture_device_factory.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/fake_video_capture_device_factory.cc
@@ -208,7 +208,7 @@ void FakeVideoCaptureDeviceFactory::GetD
   for (const auto& entry : devices_config_) {
     device_descriptors->emplace_back(
         base::StringPrintf("fake_device_%d", entry_index), entry.device_id,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE
 #elif defined(OS_MACOSX)
         VideoCaptureApi::MACOSX_AVFOUNDATION
