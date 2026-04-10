$NetBSD: patch-media_capture_video_linux_v4l2__capture__device.h,v 1.17 2026/04/10 17:31:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/capture/video/linux/v4l2_capture_device.h.orig	2026-04-06 16:25:54.000000000 +0000
+++ media/capture/video/linux/v4l2_capture_device.h
@@ -23,7 +23,7 @@ class CAPTURE_EXPORT V4L2CaptureDevice
 
   virtual int open(const char* device_name, int flags) = 0;
   virtual int close(int fd) = 0;
-  virtual int ioctl(int fd, int request, void* argp) = 0;
+  virtual int ioctl(int fd, unsigned long request, void* argp) = 0;
   virtual void* mmap(void* start,
                      size_t length,
                      int prot,
