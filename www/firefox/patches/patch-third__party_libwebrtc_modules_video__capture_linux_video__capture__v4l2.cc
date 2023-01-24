$NetBSD: patch-third__party_libwebrtc_modules_video__capture_linux_video__capture__v4l2.cc,v 1.2 2023/01/24 17:57:09 nia Exp $

* Fix build under NetBSD 9 and older.
  The older NetBSD's sys/videoio.h does not have v4l2_capability.device_caps.

--- third_party/libwebrtc/modules/video_capture/linux/video_capture_v4l2.cc.orig	2022-10-06 21:19:29.000000000 +0000
+++ third_party/libwebrtc/modules/video_capture/linux/video_capture_v4l2.cc
@@ -77,6 +77,7 @@ int32_t VideoCaptureModuleV4L2::Init(con
     if ((fd = open(device, O_RDONLY)) != -1) {
       // query device capabilities
       struct v4l2_capability cap;
+#if defined(VIDIOC_QUERYCAP)
       if (ioctl(fd, VIDIOC_QUERYCAP, &cap) == 0) {
         if (cap.bus_info[0] != 0) {
           if (strncmp((const char*)cap.bus_info,
@@ -89,6 +90,7 @@ int32_t VideoCaptureModuleV4L2::Init(con
           }
         }
       }
+#endif
       close(fd);  // close since this is not the matching device
     }
   }
