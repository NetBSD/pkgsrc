$NetBSD: patch-media_webrtc_trunk_webrtc_modules_video__capture_linux_device__info__linux.cc,v 1.1 2021/09/08 22:19:50 nia Exp $

* Fix buiuld under NetBSD.
  NetBSD's sys/videoio.h does not have v4l2_capability.device_caps
  and video capture does not work for me anyway.

--- third_party/libwebrtc/webrtc/modules/video_capture/linux/device_info_linux.cc.orig	2021-05-20 21:30:20.000000000 +0000
+++ third_party/libwebrtc/webrtc/modules/video_capture/linux/device_info_linux.cc
@@ -207,10 +207,12 @@ uint32_t DeviceInfoLinux::NumberOfDevice
     sprintf(device, "/dev/video%d", n);
     if ((fd = open(device, O_RDONLY)) != -1) {
       // query device capabilities and make sure this is a video capture device
+#if !defined(__NetBSD__)
       if (ioctl(fd, VIDIOC_QUERYCAP, &cap) < 0 || !IsVideoCaptureDevice(&cap)) {
         close(fd);
         continue;
       }
+#endif
 
       close(fd);
       count++;
@@ -241,10 +243,12 @@ int32_t DeviceInfoLinux::GetDeviceName(u
     sprintf(device, "/dev/video%d", device_index);
     if ((fd = open(device, O_RDONLY)) != -1) {
       // query device capabilities and make sure this is a video capture device
+#if !defined(__NetBSD__)
       if (ioctl(fd, VIDIOC_QUERYCAP, &cap) < 0 || !IsVideoCaptureDevice(&cap)) {
         close(fd);
         continue;
       }
+#endif
       if (count == deviceNumber) {
         // Found the device
         found = true;
@@ -328,10 +332,12 @@ int32_t DeviceInfoLinux::CreateCapabilit
     struct v4l2_capability cap;
     if (ioctl(fd, VIDIOC_QUERYCAP, &cap) == 0) {
       // skip devices without video capture capability
+#if !defined(__NetBSD__)
       if (!IsVideoCaptureDevice(&cap)) {
         close(fd);
         continue;
       }
+#endif
 
       if (cap.bus_info[0] != 0) {
         if (strncmp((const char*)cap.bus_info, (const char*)deviceUniqueIdUTF8,
@@ -384,6 +390,7 @@ bool DeviceInfoLinux::IsDeviceNameMatche
   return false;
 }
 
+#ifndef __NetBSD__
 bool DeviceInfoLinux::IsVideoCaptureDevice(struct v4l2_capability* cap)
 {
   if (cap->capabilities & V4L2_CAP_DEVICE_CAPS) {
@@ -392,6 +399,7 @@ bool DeviceInfoLinux::IsVideoCaptureDevi
     return cap->capabilities & V4L2_CAP_VIDEO_CAPTURE;
   }
 }
+#endif
 
 int32_t DeviceInfoLinux::FillCapabilities(int fd) {
   // set image format
