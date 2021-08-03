$NetBSD: patch-src_3rdparty_chromium_media_capture_video_create__video__capture__device__factory.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/media/capture/video/create_video_capture_device_factory.cc.orig	2020-07-08 21:40:45.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/create_video_capture_device_factory.cc
@@ -10,7 +10,7 @@
 #include "media/capture/video/fake_video_capture_device_factory.h"
 #include "media/capture/video/file_video_capture_device_factory.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "media/capture/video/linux/video_capture_device_factory_linux.h"
 #elif defined(OS_CHROMEOS)
 #include "media/capture/video/chromeos/camera_app_device_bridge_impl.h"
@@ -82,7 +82,7 @@ CreateChromeOSVideoCaptureDeviceFactory(
 std::unique_ptr<VideoCaptureDeviceFactory>
 CreatePlatformSpecificVideoCaptureDeviceFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   return std::make_unique<VideoCaptureDeviceFactoryLinux>(ui_task_runner);
 #elif defined(OS_CHROMEOS)
   return CreateChromeOSVideoCaptureDeviceFactory(ui_task_runner, {});
