$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_video__capture_linux_device__info__linux.cc,v 1.5 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/video_capture/linux/device_info_linux.cc.orig	2014-06-13 00:46:10.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/video_capture/linux/device_info_linux.cc
@@ -18,17 +18,28 @@
 #include <sys/stat.h>
 #include <unistd.h>
 //v4l includes
-#if defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/videoio.h>
 #elif defined(__sun)
 #include <sys/videodev2.h>
 #else
 #include <linux/videodev2.h>
 #endif
+#ifdef HAVE_LIBV4L2
+#include <libv4l2.h>
+#endif
 
 #include "webrtc/system_wrappers/interface/ref_count.h"
 #include "webrtc/system_wrappers/interface/trace.h"
 
+#ifdef HAVE_LIBV4L2
+#define open	v4l2_open
+#define close	v4l2_close
+#define dup	v4l2_dup
+#define ioctl	v4l2_ioctl
+#define mmap	v4l2_mmap
+#define munmap	v4l2_munmap
+#endif
 
 namespace webrtc
 {
@@ -136,6 +147,11 @@ int32_t DeviceInfoLinux::GetDeviceName(
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
