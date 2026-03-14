$NetBSD: patch-media_capture_video_linux_video__capture__device__factory__v4l2.cc,v 1.16 2026/03/14 12:40:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/capture/video/linux/video_capture_device_factory_v4l2.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ media/capture/video/linux/video_capture_device_factory_v4l2.cc
@@ -28,7 +28,7 @@
 #include "media/capture/video/linux/scoped_v4l2_device_fd.h"
 #include "media/capture/video/linux/video_capture_device_linux.h"
 
-#if BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_NETBSD)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
@@ -43,6 +43,7 @@ bool CompareCaptureDevices(const VideoCa
   return a.descriptor < b.descriptor;
 }
 
+#if !BUILDFLAG(IS_OPENBSD) && !BUILDFLAG(IS_NETBSD)
 // USB VID and PID are both 4 bytes long.
 const size_t kVidPidSize = 4;
 const size_t kMaxInterfaceNameSize = 256;
@@ -75,11 +76,24 @@ std::string ExtractFileNameFromDeviceId(
   DCHECK(base::StartsWith(device_id, kDevDir, base::CompareCase::SENSITIVE));
   return device_id.substr(strlen(kDevDir), device_id.length());
 }
+#endif
 
 class DevVideoFilePathsDeviceProvider
     : public VideoCaptureDeviceFactoryV4L2::DeviceProvider {
  public:
   void GetDeviceIds(std::vector<std::string>* target_container) override {
+#if BUILDFLAG(IS_OPENBSD)
+    char device[12];
+    int fd;
+    /* unveil(2) limits access to /dev/, try /dev/video[0-7] */
+    for (int n = 0; n < 8; n++) {
+      snprintf(device, sizeof(device), "/dev/video%d", n);
+      if ((fd = open(device, O_RDONLY)) != -1) {
+        close(fd);
+        target_container->emplace_back(device);
+      }
+    }
+#else
     const base::FilePath path("/dev/");
     base::FileEnumerator enumerator(path, false, base::FileEnumerator::FILES,
                                     "video*");
@@ -87,9 +101,13 @@ class DevVideoFilePathsDeviceProvider
       const base::FileEnumerator::FileInfo info = enumerator.GetInfo();
       target_container->emplace_back(path.value() + info.GetName().value());
     }
+#endif
   }
 
   std::string GetDeviceModelId(const std::string& device_id) override {
+#if BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_NETBSD)
+    return std::string();
+#else
     const std::string file_name = ExtractFileNameFromDeviceId(device_id);
     std::string usb_id;
     const std::string vid_path =
@@ -106,9 +124,13 @@ class DevVideoFilePathsDeviceProvider
     }
 
     return usb_id;
+#endif
   }
 
   std::string GetDeviceDisplayName(const std::string& device_id) override {
+#if BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_NETBSD)
+    return std::string();
+#else
     const std::string file_name = ExtractFileNameFromDeviceId(device_id);
     const std::string interface_path =
         base::StringPrintf(kInterfacePathTemplate, file_name.c_str());
@@ -119,6 +141,7 @@ class DevVideoFilePathsDeviceProvider
       return std::string();
     }
     return display_name;
+#endif
   }
 };
 
@@ -224,7 +247,7 @@ void VideoCaptureDeviceFactoryV4L2::GetD
   std::move(callback).Run(std::move(devices_info));
 }
 
-int VideoCaptureDeviceFactoryV4L2::DoIoctl(int fd, int request, void* argp) {
+int VideoCaptureDeviceFactoryV4L2::DoIoctl(int fd, unsigned int request, void* argp) {
   return HANDLE_EINTR(v4l2_->ioctl(fd, request, argp));
 }
 
@@ -284,6 +307,11 @@ std::vector<float> VideoCaptureDeviceFac
         frame_rates.push_back(
             frame_interval.discrete.denominator /
             static_cast<float>(frame_interval.discrete.numerator));
+#if BUILDFLAG(IS_NETBSD)
+        // On NetBSD VIDIOC_ENUM_FRAMEINTERVALS(video_enum_frameival) always return the same values
+        // and not handle index, what is cause infinity loop. One round is enough.
+        break;
+#endif
       }
     } else if (frame_interval.type == V4L2_FRMIVAL_TYPE_CONTINUOUS ||
                frame_interval.type == V4L2_FRMIVAL_TYPE_STEPWISE) {
