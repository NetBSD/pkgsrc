$NetBSD: patch-src_3rdparty_chromium_media_capture_video_linux_video__capture__device__factory__v4l2.h,v 1.1 2025/12/21 09:38:32 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/capture/video/linux/video_capture_device_factory_v4l2.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/linux/video_capture_device_factory_v4l2.h
@@ -51,7 +51,7 @@ class CAPTURE_EXPORT VideoCaptureDeviceF
 
  private:
   // Simple wrapper to do HANDLE_EINTR(v4l2_->ioctl(fd, ...)).
-  int DoIoctl(int fd, int request, void* argp);
+  int DoIoctl(int fd, unsigned int request, void* argp);
 
   VideoCaptureControlSupport GetControlSupport(int fd);
   bool GetControlSupport(int fd, int control_id);
