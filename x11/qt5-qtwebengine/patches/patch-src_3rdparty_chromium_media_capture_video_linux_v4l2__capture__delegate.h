$NetBSD: patch-src_3rdparty_chromium_media_capture_video_linux_v4l2__capture__delegate.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.h.orig	2020-07-15 18:55:59.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.h
@@ -20,7 +20,7 @@
 #include "media/capture/video/linux/v4l2_capture_device_impl.h"
 #include "media/capture/video/video_capture_device.h"
 
-#if defined(OS_OPENBSD)
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
