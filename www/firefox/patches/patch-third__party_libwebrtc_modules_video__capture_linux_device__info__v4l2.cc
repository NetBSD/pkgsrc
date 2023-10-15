$NetBSD: patch-third__party_libwebrtc_modules_video__capture_linux_device__info__v4l2.cc,v 1.3 2023/10/15 07:40:10 ryoon Exp $

* Fix build under NetBSD 9 and older.
  The older NetBSD's sys/videoio.h does not have v4l2_capability.device_caps.

--- third_party/libwebrtc/modules/video_capture/linux/device_info_v4l2.cc.orig	2023-09-14 21:15:08.000000000 +0000
+++ third_party/libwebrtc/modules/video_capture/linux/device_info_v4l2.cc
@@ -211,11 +211,13 @@ uint32_t DeviceInfoV4l2::NumberOfDevices
   for (int n = 0; n < 64; n++) {
     snprintf(device, sizeof(device), "/dev/video%d", n);
     if ((fd = open(device, O_RDONLY)) != -1) {
+#if defined(VIDIOC_QUERYCAP)
       // query device capabilities and make sure this is a video capture device
       if (ioctl(fd, VIDIOC_QUERYCAP, &cap) < 0 || !IsVideoCaptureDevice(&cap)) {
         close(fd);
         continue;
       }
+#endif
 
       close(fd);
       count++;
@@ -242,11 +244,13 @@ int32_t DeviceInfoV4l2::GetDeviceName(ui
   for (int n = 0; n < 64; n++) {
     snprintf(device, sizeof(device), "/dev/video%d", n);
     if ((fd = open(device, O_RDONLY)) != -1) {
+#if defined(VIDIOC_QUERYCAP)
       // query device capabilities and make sure this is a video capture device
       if (ioctl(fd, VIDIOC_QUERYCAP, &cap) < 0 || !IsVideoCaptureDevice(&cap)) {
         close(fd);
         continue;
       }
+#endif
       if (count == deviceNumber) {
         // Found the device
         found = true;
@@ -317,6 +321,7 @@ int32_t DeviceInfoV4l2::CreateCapability
     if (fd == -1)
       continue;
 
+#if defined(VIDIOC_QUERYCAP)
     // query device capabilities
     struct v4l2_capability cap;
     if (ioctl(fd, VIDIOC_QUERYCAP, &cap) == 0) {
@@ -341,6 +346,7 @@ int32_t DeviceInfoV4l2::CreateCapability
         }
       }
     }
+#endif
     close(fd);  // close since this is not the matching device
   }
 
@@ -386,11 +392,15 @@ bool DeviceInfoV4l2::IsDeviceNameMatches
 
 bool DeviceInfoV4l2::IsVideoCaptureDevice(struct v4l2_capability* cap)
 {
+#if defined(V4L2_CAP_DEVICE_CAPS)
   if (cap->capabilities & V4L2_CAP_DEVICE_CAPS) {
     return cap->device_caps & V4L2_CAP_VIDEO_CAPTURE;
   } else {
     return cap->capabilities & V4L2_CAP_VIDEO_CAPTURE;
   }
+#else
+    return cap->capabilities & V4L2_CAP_VIDEO_CAPTURE;
+#endif
 }
 
 int32_t DeviceInfoV4l2::FillCapabilities(int fd) {
