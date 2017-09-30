$NetBSD: patch-media_webrtc_trunk_webrtc_modules_video__capture_linux_device__info__linux.cc,v 1.14 2017/09/30 05:34:12 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/video_capture/linux/device_info_linux.cc.orig	2017-09-14 20:16:07.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/video_capture/linux/device_info_linux.cc
@@ -25,6 +25,9 @@
 #else
 #include <linux/videodev2.h>
 #endif
+#ifdef HAVE_LIBV4L2
+#include <libv4l2.h>
+#endif
 
 #include "webrtc/system_wrappers/include/trace.h"
 
@@ -33,6 +36,15 @@
 #define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )
 #endif
 
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
@@ -314,6 +326,11 @@ int32_t DeviceInfoLinux::GetDeviceName(
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
