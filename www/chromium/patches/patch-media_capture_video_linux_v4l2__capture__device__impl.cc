$NetBSD: patch-media_capture_video_linux_v4l2__capture__device__impl.cc,v 1.5 2025/08/13 07:44:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/capture/video/linux/v4l2_capture_device_impl.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ media/capture/video/linux/v4l2_capture_device_impl.cc
@@ -22,7 +22,7 @@ int V4L2CaptureDeviceImpl::close(int fd)
   return ::close(fd);
 }
 
-int V4L2CaptureDeviceImpl::ioctl(int fd, int request, void* argp) {
+int V4L2CaptureDeviceImpl::ioctl(int fd, unsigned long request, void* argp) {
   return ::ioctl(fd, request, argp);
 }
 
