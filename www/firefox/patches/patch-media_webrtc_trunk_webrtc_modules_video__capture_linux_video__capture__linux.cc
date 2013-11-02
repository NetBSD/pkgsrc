$NetBSD: patch-media_webrtc_trunk_webrtc_modules_video__capture_linux_video__capture__linux.cc,v 1.3 2013/11/02 22:57:55 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/video_capture/linux/video_capture_linux.cc.orig	2013-10-25 22:27:35.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/video_capture/linux/video_capture_linux.cc
@@ -18,13 +18,16 @@
 #include <string.h>
 
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
 
 #include <new>
 
@@ -34,6 +37,15 @@
 #include "critical_section_wrapper.h"
 #include "video_capture_linux.h"
 
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
