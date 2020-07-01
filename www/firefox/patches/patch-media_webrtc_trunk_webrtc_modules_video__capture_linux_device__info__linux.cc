$NetBSD: patch-media_webrtc_trunk_webrtc_modules_video__capture_linux_device__info__linux.cc,v 1.16 2020/07/01 13:01:01 ryoon Exp $

* Fix buiuld under NetBSD.
  NetBSD's sys/videoio.h does not have v4l2_capability.device_caps
  and video capture does not work for me anyway.

--- media/webrtc/trunk/webrtc/modules/video_capture/linux/device_info_linux.cc.orig	2020-06-19 00:11:06.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/video_capture/linux/device_info_linux.cc
@@ -207,10 +207,12 @@ uint32_t DeviceInfoLinux::NumberOfDevice
     sprintf(device, "/dev/video%d", n);
     if ((fd = open(device, O_RDONLY)) != -1) {
       // query device capabilities and make sure this is a video capture device
+#if !defined(__NetBSD__)
       if (ioctl(fd, VIDIOC_QUERYCAP, &cap) < 0 || !(cap.device_caps & V4L2_CAP_VIDEO_CAPTURE)) {
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
       if (ioctl(fd, VIDIOC_QUERYCAP, &cap) < 0 || !(cap.device_caps & V4L2_CAP_VIDEO_CAPTURE)) {
         close(fd);
         continue;
       }
+#endif
       if (count == deviceNumber) {
         // Found the device
         found = true;
@@ -328,9 +332,11 @@ int32_t DeviceInfoLinux::CreateCapabilit
     struct v4l2_capability cap;
     if (ioctl(fd, VIDIOC_QUERYCAP, &cap) == 0) {
       // skip devices without video capture capability
+#if !defined(__NetBSD__)
       if (!(cap.device_caps & V4L2_CAP_VIDEO_CAPTURE)) {
         continue;
       }
+#endif
 
       if (cap.bus_info[0] != 0) {
         if (strncmp((const char*)cap.bus_info, (const char*)deviceUniqueIdUTF8,
