$NetBSD: patch-src_3rdparty_chromium_media_capture_video_linux_v4l2__capture__delegate.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.cc
@@ -4,8 +4,12 @@
 
 #include "media/capture/video/linux/v4l2_capture_delegate.h"
 
+#if defined(OS_LINUX)
 #include <linux/version.h>
 #include <linux/videodev2.h>
+#else
+#include <sys/videoio.h>
+#endif
 #include <poll.h>
 #include <sys/fcntl.h>
 #include <sys/ioctl.h>
@@ -13,7 +17,7 @@
 
 #include <utility>
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 #include <linux/version.h>
 #endif
 
@@ -28,10 +32,12 @@
 
 using media::mojom::MeteringMode;
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
+#if defined(OS_LINUX)
+#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0) || defined(OS_BSD)
 // 16 bit depth, Realsense F200.
 #define V4L2_PIX_FMT_Z16 v4l2_fourcc('Z', '1', '6', ' ')
 #endif
+#endif
 
 // TODO(aleksandar.stojiljkovic): Wrap this with kernel version check once the
 // format is introduced to kernel.
@@ -70,8 +76,10 @@ struct {
   size_t num_planes;
 } constexpr kSupportedFormatsAndPlanarity[] = {
     {V4L2_PIX_FMT_YUV420, PIXEL_FORMAT_I420, 1},
+#if !defined(OS_NETBSD)
     {V4L2_PIX_FMT_Y16, PIXEL_FORMAT_Y16, 1},
     {V4L2_PIX_FMT_Z16, PIXEL_FORMAT_Y16, 1},
+#endif
     {V4L2_PIX_FMT_INVZ, PIXEL_FORMAT_Y16, 1},
     {V4L2_PIX_FMT_YUYV, PIXEL_FORMAT_YUY2, 1},
     {V4L2_PIX_FMT_RGB24, PIXEL_FORMAT_RGB24, 1},
@@ -90,11 +98,13 @@ struct {
 constexpr int kMaxIOCtrlRetries = 5;
 
 // Base id and class identifier for Controls to be reset.
+#if !defined(OS_NETBSD)
 struct {
   uint32_t control_base;
   uint32_t class_id;
 } constexpr kControls[] = {{V4L2_CID_USER_BASE, V4L2_CID_USER_CLASS},
                            {V4L2_CID_CAMERA_CLASS_BASE, V4L2_CID_CAMERA_CLASS}};
+#endif
 
 // Fill in |format| with the given parameters.
 void FillV4L2Format(v4l2_format* format,
@@ -127,9 +137,11 @@ void FillV4L2RequestBuffer(v4l2_requestb
 bool IsSpecialControl(int control_id) {
   switch (control_id) {
     case V4L2_CID_AUTO_WHITE_BALANCE:
+#if !defined(OS_NETBSD)
     case V4L2_CID_EXPOSURE_AUTO:
     case V4L2_CID_EXPOSURE_AUTO_PRIORITY:
     case V4L2_CID_FOCUS_AUTO:
+#endif
       return true;
   }
   return false;
@@ -146,6 +158,7 @@ bool IsSpecialControl(int control_id) {
 #define V4L2_CID_PANTILT_CMD (V4L2_CID_CAMERA_CLASS_BASE + 34)
 #endif
 bool IsBlockedControl(int control_id) {
+#if !defined(OS_NETBSD)
   switch (control_id) {
     case V4L2_CID_PAN_RELATIVE:
     case V4L2_CID_TILT_RELATIVE:
@@ -161,6 +174,7 @@ bool IsBlockedControl(int control_id) {
     case V4L2_CID_PANTILT_CMD:
       return true;
   }
+#endif
   return false;
 }
 
@@ -339,6 +353,7 @@ void V4L2CaptureDelegate::AllocateAndSta
 
   // Set anti-banding/anti-flicker to 50/60Hz. May fail due to not supported
   // operation (|errno| == EINVAL in this case) or plain failure.
+#if !defined(OS_NETBSD)
   if ((power_line_frequency_ == V4L2_CID_POWER_LINE_FREQUENCY_50HZ)
       || (power_line_frequency_ == V4L2_CID_POWER_LINE_FREQUENCY_60HZ)
 #if LINUX_VERSION_CODE >= KERNEL_VERSION(3,2,0)
@@ -352,6 +367,7 @@ void V4L2CaptureDelegate::AllocateAndSta
     if (retval != 0)
       DVLOG(1) << "Error setting power line frequency removal";
   }
+#endif
 
   capture_format_.frame_size.SetSize(video_fmt_.fmt.pix.width,
                                      video_fmt_.fmt.pix.height);
@@ -391,6 +407,7 @@ void V4L2CaptureDelegate::GetPhotoState(
 
   mojom::PhotoStatePtr photo_capabilities = mojo::CreateEmptyPhotoState();
 
+#if !defined(OS_NETBSD)
   photo_capabilities->pan = RetrieveUserControlRange(V4L2_CID_PAN_ABSOLUTE);
   photo_capabilities->tilt = RetrieveUserControlRange(V4L2_CID_TILT_ABSOLUTE);
   photo_capabilities->zoom = RetrieveUserControlRange(V4L2_CID_ZOOM_ABSOLUTE);
@@ -488,6 +505,7 @@ void V4L2CaptureDelegate::GetPhotoState(
   photo_capabilities->saturation =
       RetrieveUserControlRange(V4L2_CID_SATURATION);
   photo_capabilities->sharpness = RetrieveUserControlRange(V4L2_CID_SHARPNESS);
+#endif
 
   std::move(callback).Run(std::move(photo_capabilities));
 }
@@ -499,6 +517,7 @@ void V4L2CaptureDelegate::SetPhotoOption
   if (!device_fd_.is_valid() || !is_capturing_)
     return;
 
+#if !defined(OS_NETBSD)
   if (settings->has_pan) {
     v4l2_control pan_current = {};
     pan_current.id = V4L2_CID_PAN_ABSOLUTE;
@@ -610,6 +629,7 @@ void V4L2CaptureDelegate::SetPhotoOption
       DoIoctl(VIDIOC_S_CTRL, &set_exposure_time);
     }
   }
+#endif
 
   if (settings->has_brightness) {
     v4l2_control current = {};
@@ -693,6 +713,7 @@ mojom::RangePtr V4L2CaptureDelegate::Ret
 }
 
 void V4L2CaptureDelegate::ResetUserAndCameraControlsToDefault() {
+#if !defined(OS_NETBSD)
   // Set V4L2_CID_AUTO_WHITE_BALANCE to false first.
   v4l2_control auto_white_balance = {};
   auto_white_balance.id = V4L2_CID_AUTO_WHITE_BALANCE;
@@ -788,6 +809,7 @@ void V4L2CaptureDelegate::ResetUserAndCa
   ext_controls.controls = special_camera_controls.data();
   if (DoIoctl(VIDIOC_S_EXT_CTRLS, &ext_controls) < 0)
     DPLOG(INFO) << "VIDIOC_S_EXT_CTRLS";
+#endif
 }
 
 bool V4L2CaptureDelegate::MapAndQueueBuffer(int index) {
