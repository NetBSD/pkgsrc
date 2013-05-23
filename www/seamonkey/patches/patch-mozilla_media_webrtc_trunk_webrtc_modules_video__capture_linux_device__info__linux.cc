$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_video__capture_linux_device__info__linux.cc,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/video_capture/linux/device_info_linux.cc.orig	2013-05-03 03:08:07.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/video_capture/linux/device_info_linux.cc
@@ -19,12 +19,30 @@
 #include <stdlib.h>
 
 //v4l includes
+#if defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <sys/videoio.h>
+#elif defined(__sun)
+#include <sys/videodev2.h>
+#else
 #include <linux/videodev2.h>
+#endif
+#ifdef HAVE_LIBV4L2
+#include <libv4l2.h>
+#endif
 
 #include "ref_count.h"
 #include "trace.h"
 
 
+#ifdef HAVE_LIBV4L2
+#define open	v4l2_open
+#define close	v4l2_close
+#define dup	v4l2_dup
+#define ioctl	v4l2_ioctl
+#define mmap	v4l2_mmap
+#define munmap	v4l2_munmap
+#endif
+
 namespace webrtc
 {
 namespace videocapturemodule
@@ -130,6 +148,11 @@ WebRtc_Word32 DeviceInfoLinux::GetDevice
     memset(deviceNameUTF8, 0, deviceNameLength);
     memcpy(cameraName, cap.card, sizeof(cap.card));
 
+    if (cameraName[0] == '\0')
+    {
+        sprintf(cameraName, "Camera at /dev/video%d", deviceNumber);
+    }
+
     if (deviceNameLength >= strlen(cameraName))
     {
         memcpy(deviceNameUTF8, cameraName, strlen(cameraName));
