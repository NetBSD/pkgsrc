$NetBSD: patch-media_capture_video_linux_fake__v4l2__impl.h,v 1.14 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/capture/video/linux/fake_v4l2_impl.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ media/capture/video/linux/fake_v4l2_impl.h
@@ -8,7 +8,13 @@
 #include <map>
 #include <string>
 
+#include "build/build_config.h"
+#if BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_NETBSD)
+#include <sys/videoio.h>
+typedef __uint32_t __u32;
+#else
 #include <linux/videodev2.h>
+#endif
 
 #include "base/synchronization/lock.h"
 #include "media/capture/capture_export.h"
@@ -38,7 +44,7 @@ class CAPTURE_EXPORT FakeV4L2Impl : publ
   // Implementation of V4L2CaptureDevice interface:
   int open(const char* device_name, int flags) override;
   int close(int fd) override;
-  int ioctl(int fd, int request, void* argp) override;
+  int ioctl(int fd, unsigned long request, void* argp) override;
   void* mmap(void* start,
              size_t length,
              int prot,
