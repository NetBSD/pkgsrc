$NetBSD: patch-src_3rdparty_chromium_media_capture_video_linux_v4l2__capture__device__factory__linux.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/media/capture/video/linux/video_capture_device_factory_linux.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/linux/video_capture_device_factory_linux.cc
@@ -21,7 +21,7 @@
 #include "media/capture/video/linux/scoped_v4l2_device_fd.h"
 #include "media/capture/video/linux/video_capture_device_linux.h"
 
-#if defined(OS_OPENBSD)
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
@@ -244,9 +244,12 @@ int VideoCaptureDeviceFactoryLinux::DoIo
 VideoCaptureControlSupport VideoCaptureDeviceFactoryLinux::GetControlSupport(
     int fd) {
   VideoCaptureControlSupport control_support;
+#if !defined(OS_NETBSD)
+  // XXXX need to sort correct values
   control_support.pan = GetControlSupport(fd, V4L2_CID_PAN_ABSOLUTE);
   control_support.tilt = GetControlSupport(fd, V4L2_CID_TILT_ABSOLUTE);
   control_support.zoom = GetControlSupport(fd, V4L2_CID_ZOOM_ABSOLUTE);
+#endif
   return control_support;
 }
 
@@ -281,6 +284,7 @@ std::vector<float> VideoCaptureDeviceFac
     uint32_t fourcc,
     uint32_t width,
     uint32_t height) {
+#if !defined(OS_NETBSD)
   std::vector<float> frame_rates;
 
   v4l2_frmivalenum frame_interval = {};
@@ -307,6 +311,9 @@ std::vector<float> VideoCaptureDeviceFac
   if (frame_rates.empty())
     frame_rates.push_back(0);
   return frame_rates;
+#else
+  NOTIMPLEMENTED_LOG_ONCE();
+#endif
 }
 
 void VideoCaptureDeviceFactoryLinux::GetSupportedFormatsForV4L2BufferType(
