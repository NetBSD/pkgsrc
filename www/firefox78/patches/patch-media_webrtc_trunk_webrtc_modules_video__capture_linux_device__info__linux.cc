$NetBSD: patch-media_webrtc_trunk_webrtc_modules_video__capture_linux_device__info__linux.cc,v 1.1 2020/07/30 08:09:28 nia Exp $

NetBSD videoio lacks V4L2_CAP_DEVICE_CAPS

--- media/webrtc/trunk/webrtc/modules/video_capture/linux/device_info_linux.cc.orig	2020-07-22 15:56:23.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/video_capture/linux/device_info_linux.cc
@@ -385,11 +385,15 @@ bool DeviceInfoLinux::IsDeviceNameMatche
 
 bool DeviceInfoLinux::IsVideoCaptureDevice(struct v4l2_capability* cap)
 {
+#ifdef V4L2_CAP_DEVICE_CAPS
   if (cap->capabilities & V4L2_CAP_DEVICE_CAPS) {
     return cap->device_caps & V4L2_CAP_VIDEO_CAPTURE;
   } else {
     return cap->capabilities & V4L2_CAP_VIDEO_CAPTURE;
   }
+#else
+  return 1;
+#endif
 }
 
 int32_t DeviceInfoLinux::FillCapabilities(int fd) {
