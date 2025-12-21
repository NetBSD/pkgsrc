$NetBSD: patch-src_3rdparty_chromium_media_capture_video_linux_v4l2__capture__device.h,v 1.1 2025/12/21 09:38:32 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_device.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_device.h
@@ -21,7 +21,7 @@ class CAPTURE_EXPORT V4L2CaptureDevice
  public:
   virtual int open(const char* device_name, int flags) = 0;
   virtual int close(int fd) = 0;
-  virtual int ioctl(int fd, int request, void* argp) = 0;
+  virtual int ioctl(int fd, unsigned long request, void* argp) = 0;
   virtual void* mmap(void* start,
                      size_t length,
                      int prot,
