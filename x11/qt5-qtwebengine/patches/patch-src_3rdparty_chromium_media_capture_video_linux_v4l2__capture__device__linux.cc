$NetBSD: patch-src_3rdparty_chromium_media_capture_video_linux_v4l2__capture__device__linux.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/media/capture/video/linux/video_capture_device_linux.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/linux/video_capture_device_linux.cc
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "media/capture/video/linux/v4l2_capture_delegate.h"
 
-#if defined(OS_OPENBSD)
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
@@ -24,6 +24,7 @@ namespace media {
 
 namespace {
 
+#if !defined(OS_NETBSD)
 int TranslatePowerLineFrequencyToV4L2(PowerLineFrequency frequency) {
   switch (frequency) {
     case PowerLineFrequency::FREQUENCY_50HZ:
@@ -39,6 +40,7 @@ int TranslatePowerLineFrequencyToV4L2(Po
 #endif
   }
 }
+#endif
 
 }  // namespace
 
@@ -75,6 +77,7 @@ VideoCaptureDeviceLinux::~VideoCaptureDe
 void VideoCaptureDeviceLinux::AllocateAndStart(
     const VideoCaptureParams& params,
     std::unique_ptr<VideoCaptureDevice::Client> client) {
+#if !defined(OS_NETBSD)
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!capture_impl_);
   if (v4l2_thread_.IsRunning())
@@ -103,6 +106,7 @@ void VideoCaptureDeviceLinux::AllocateAn
   for (auto& request : photo_requests_queue_)
     v4l2_thread_.task_runner()->PostTask(FROM_HERE, std::move(request));
   photo_requests_queue_.clear();
+#endif
 }
 
 void VideoCaptureDeviceLinux::StopAndDeAllocate() {
