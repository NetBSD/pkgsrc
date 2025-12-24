$NetBSD: patch-third__party_libwebrtc_modules_video__capture_linux_video__capture__v4l2.cc,v 1.3 2025/12/24 15:26:41 ryoon Exp $

* Fix build under NetBSD 9 and older.
  The older NetBSD's sys/videoio.h does not have v4l2_capability.device_caps.
* On NetBSD, some uvideo(4) devices are not usable. They returns
  fmt.pixelformat as zero from VIDIOC_ENUM_FMT. Exclude unsupported devices
  in early stage.

--- third_party/libwebrtc/modules/video_capture/linux/video_capture_v4l2.cc.orig	2025-12-05 17:43:20.000000000 +0000
+++ third_party/libwebrtc/modules/video_capture/linux/video_capture_v4l2.cc
@@ -90,18 +90,28 @@ int32_t VideoCaptureModuleV4L2::Init(con
     if ((fd = open(device, O_RDONLY)) != -1) {
       // query device capabilities
       struct v4l2_capability cap;
+#if defined(VIDIOC_QUERYCAP)
       if (ioctl(fd, VIDIOC_QUERYCAP, &cap) == 0) {
         if (cap.bus_info[0] != 0) {
           if (strncmp((const char*)cap.bus_info,
                       (const char*)deviceUniqueIdUTF8,
                       strlen((const char*)deviceUniqueIdUTF8)) ==
               0) {  // match with device id
-            close(fd);
-            found = true;
-            break;  // fd matches with device unique id supplied
+            struct v4l2_fmtdesc fmt;
+            memset(&fmt, 0, sizeof(fmt));
+            fmt.index = 0;
+            fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
+            if (ioctl(fd, VIDIOC_ENUM_FMT, &fmt) == 0) {
+              if (fmt.pixelformat != 0) {
+                close(fd);
+                found = true;
+                break;  // fd matches with device unique id supplied
+              }
+            }
           }
         }
       }
+#endif
       close(fd);  // close since this is not the matching device
     }
   }
