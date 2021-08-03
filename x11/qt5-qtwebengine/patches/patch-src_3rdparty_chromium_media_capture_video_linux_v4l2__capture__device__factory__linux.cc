$NetBSD: patch-src_3rdparty_chromium_media_capture_video_linux_v4l2__capture__device__factory__linux.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/media/capture/video/linux/video_capture_device_factory_linux.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/linux/video_capture_device_factory_linux.cc
@@ -21,7 +21,7 @@
 #include "media/capture/video/linux/scoped_v4l2_device_fd.h"
 #include "media/capture/video/linux/video_capture_device_linux.h"
 
-#if defined(OS_OPENBSD)
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
@@ -277,6 +277,7 @@ std::vector<float> VideoCaptureDeviceFac
     uint32_t fourcc,
     uint32_t width,
     uint32_t height) {
+#if !defined(OS_NETBSD)
   std::vector<float> frame_rates;
 
   v4l2_frmivalenum frame_interval = {};
@@ -303,6 +304,9 @@ std::vector<float> VideoCaptureDeviceFac
   if (frame_rates.empty())
     frame_rates.push_back(0);
   return frame_rates;
+#else
+  NOTIMPLEMENTED_LOG_ONCE();
+#endif
 }
 
 void VideoCaptureDeviceFactoryLinux::GetSupportedFormatsForV4L2BufferType(
