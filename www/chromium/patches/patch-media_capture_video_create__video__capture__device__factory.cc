$NetBSD: patch-media_capture_video_create__video__capture__device__factory.cc,v 1.1 2025/02/06 09:58:12 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/capture/video/create_video_capture_device_factory.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/capture/video/create_video_capture_device_factory.cc
@@ -13,7 +13,7 @@
 #include "media/capture/video/fake_video_capture_device_factory.h"
 #include "media/capture/video/file_video_capture_device_factory.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "media/capture/video/linux/video_capture_device_factory_linux.h"
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
 #include "media/capture/video/chromeos/public/cros_features.h"
@@ -56,7 +56,7 @@ CreateFakeVideoCaptureDeviceFactory() {
 std::unique_ptr<VideoCaptureDeviceFactory>
 CreatePlatformSpecificVideoCaptureDeviceFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return std::make_unique<VideoCaptureDeviceFactoryLinux>(ui_task_runner);
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   if (base::SysInfo::IsRunningOnChromeOS())
