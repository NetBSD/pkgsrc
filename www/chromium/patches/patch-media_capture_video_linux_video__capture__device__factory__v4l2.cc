$NetBSD: patch-media_capture_video_linux_video__capture__device__factory__v4l2.cc,v 1.1 2025/02/06 09:58:12 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/capture/video/linux/video_capture_device_factory_v4l2.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/capture/video/linux/video_capture_device_factory_v4l2.cc
@@ -23,7 +23,7 @@
 #include "media/capture/video/linux/scoped_v4l2_device_fd.h"
 #include "media/capture/video/linux/video_capture_device_linux.h"
 
-#if BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_NETBSD)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
@@ -38,6 +38,7 @@ bool CompareCaptureDevices(const VideoCa
   return a.descriptor < b.descriptor;
 }
 
+#if !BUILDFLAG(IS_OPENBSD) && !BUILDFLAG(IS_NETBSD)
 // USB VID and PID are both 4 bytes long.
 const size_t kVidPidSize = 4;
 const size_t kMaxInterfaceNameSize = 256;
@@ -70,11 +71,15 @@ std::string ExtractFileNameFromDeviceId(
   DCHECK(base::StartsWith(device_id, kDevDir, base::CompareCase::SENSITIVE));
   return device_id.substr(strlen(kDevDir), device_id.length());
 }
+#endif
 
 class DevVideoFilePathsDeviceProvider
     : public VideoCaptureDeviceFactoryV4L2::DeviceProvider {
  public:
   void GetDeviceIds(std::vector<std::string>* target_container) override {
+#if BUILDFLAG(IS_OPENBSD)
+    target_container->emplace_back("/dev/video");
+#else
     const base::FilePath path("/dev/");
     base::FileEnumerator enumerator(path, false, base::FileEnumerator::FILES,
                                     "video*");
@@ -82,9 +87,13 @@ class DevVideoFilePathsDeviceProvider
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
@@ -101,9 +110,13 @@ class DevVideoFilePathsDeviceProvider
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
@@ -114,6 +127,7 @@ class DevVideoFilePathsDeviceProvider
       return std::string();
     }
     return display_name;
+#endif
   }
 };
 
@@ -219,7 +233,7 @@ void VideoCaptureDeviceFactoryV4L2::GetD
   std::move(callback).Run(std::move(devices_info));
 }
 
-int VideoCaptureDeviceFactoryV4L2::DoIoctl(int fd, int request, void* argp) {
+int VideoCaptureDeviceFactoryV4L2::DoIoctl(int fd, unsigned int request, void* argp) {
   return HANDLE_EINTR(v4l2_->ioctl(fd, request, argp));
 }
 
@@ -279,6 +293,11 @@ std::vector<float> VideoCaptureDeviceFac
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
