$NetBSD: patch-src_3rdparty_chromium_media_capture_video_linux_v4l2__capture__device__impl.h,v 1.1 2025/12/21 09:38:32 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_device_impl.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_device_impl.h
@@ -19,7 +19,7 @@ class CAPTURE_EXPORT V4L2CaptureDeviceIm
  public:
   int open(const char* device_name, int flags) override;
   int close(int fd) override;
-  int ioctl(int fd, int request, void* argp) override;
+  int ioctl(int fd, unsigned long request, void* argp) override;
   void* mmap(void* start,
              size_t length,
              int prot,
