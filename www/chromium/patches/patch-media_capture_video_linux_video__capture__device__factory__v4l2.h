$NetBSD: patch-media_capture_video_linux_video__capture__device__factory__v4l2.h,v 1.14 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/capture/video/linux/video_capture_device_factory_v4l2.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ media/capture/video/linux/video_capture_device_factory_v4l2.h
@@ -51,7 +51,7 @@ class CAPTURE_EXPORT VideoCaptureDeviceF
 
  private:
   // Simple wrapper to do HANDLE_EINTR(v4l2_->ioctl(fd, ...)).
-  int DoIoctl(int fd, int request, void* argp);
+  int DoIoctl(int fd, unsigned int request, void* argp);
 
   VideoCaptureControlSupport GetControlSupport(int fd);
   bool GetControlSupport(int fd, int control_id);
