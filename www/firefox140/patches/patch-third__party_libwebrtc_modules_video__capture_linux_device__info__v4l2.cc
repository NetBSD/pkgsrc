$NetBSD: patch-third__party_libwebrtc_modules_video__capture_linux_device__info__v4l2.cc,v 1.1 2025/10/19 11:56:57 leot Exp $

* Fix build under NetBSD 9 and older.
  The older NetBSD's sys/videoio.h does not have v4l2_capability.device_caps.

--- third_party/libwebrtc/modules/video_capture/linux/device_info_v4l2.cc.orig	2025-05-17 19:55:48.000000000 +0000
+++ third_party/libwebrtc/modules/video_capture/linux/device_info_v4l2.cc
@@ -52,14 +52,14 @@
 #define V4L2_PIX_FMT_RGBA32 v4l2_fourcc('A', 'B', '2', '4')
 #endif
 
-#ifdef WEBRTC_LINUX
+#ifdef WEBRTC_LINUX || WEBRTC_BSD
 #define EVENT_SIZE  ( sizeof (struct inotify_event) )
 #define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )
 #endif
 
 namespace webrtc {
 namespace videocapturemodule {
-#ifdef WEBRTC_LINUX
+#ifdef WEBRTC_LINUX || WEBRTC_BSD
 void DeviceInfoV4l2::HandleEvent(inotify_event* event, int fd)
 {
     if (event->mask & IN_CREATE) {
@@ -175,11 +175,11 @@ void DeviceInfoV4l2::InotifyProcess()
 #endif
 
 DeviceInfoV4l2::DeviceInfoV4l2() : DeviceInfoImpl()
-#ifdef WEBRTC_LINUX
+#ifdef WEBRTC_LINUX || WEBRTC_BSD
     , _isShutdown(false)
 #endif
 {
-#ifdef WEBRTC_LINUX
+#ifdef WEBRTC_LINUX || WEBRTC_BSD
   _inotifyEventThread = rtc::PlatformThread::SpawnJoinable(
       [this] {
         InotifyProcess();
@@ -192,7 +192,7 @@ int32_t DeviceInfoV4l2::Init() {
 }
 
 DeviceInfoV4l2::~DeviceInfoV4l2() {
-#ifdef WEBRTC_LINUX
+#ifdef WEBRTC_LINUX || WEBRTC_BSD
     _isShutdown = true;
 
     if (!_inotifyEventThread.empty()) {
@@ -211,11 +211,13 @@ uint32_t DeviceInfoV4l2::NumberOfDevices
   for (int n = 0; n < 64; n++) {
     snprintf(device, sizeof(device), "/dev/video%d", n);
     if ((fd = open(device, O_RDONLY)) != -1) {
+#if defined(VIDIOC_QUERYCAP)
       // query device capabilities and make sure this is a video capture device
       if (ioctl(fd, VIDIOC_QUERYCAP, &cap) < 0 || !IsVideoCaptureDevice(&cap)) {
         close(fd);
         continue;
       }
+#endif
 
       close(fd);
       count++;
@@ -243,11 +245,13 @@ int32_t DeviceInfoV4l2::GetDeviceName(ui
   for (int n = 0; n < 64; n++) {
     snprintf(device, sizeof(device), "/dev/video%d", n);
     if ((fd = open(device, O_RDONLY)) != -1) {
+#if defined(VIDIOC_QUERYCAP)
       // query device capabilities and make sure this is a video capture device
       if (ioctl(fd, VIDIOC_QUERYCAP, &cap) < 0 || !IsVideoCaptureDevice(&cap)) {
         close(fd);
         continue;
       }
+#endif
       if (count == deviceNumber) {
         // Found the device
         found = true;
@@ -318,6 +322,7 @@ int32_t DeviceInfoV4l2::CreateCapability
     if (fd == -1)
       continue;
 
+#if defined(VIDIOC_QUERYCAP)
     // query device capabilities
     struct v4l2_capability cap;
     if (ioctl(fd, VIDIOC_QUERYCAP, &cap) == 0) {
@@ -342,6 +347,7 @@ int32_t DeviceInfoV4l2::CreateCapability
         }
       }
     }
+#endif
     close(fd);  // close since this is not the matching device
   }
 
@@ -387,11 +393,15 @@ bool DeviceInfoV4l2::IsDeviceNameMatches
 
 bool DeviceInfoV4l2::IsVideoCaptureDevice(struct v4l2_capability* cap)
 {
+#if defined(V4L2_CAP_DEVICE_CAPS)
   if (cap->capabilities & V4L2_CAP_DEVICE_CAPS) {
     return cap->device_caps & V4L2_CAP_VIDEO_CAPTURE;
   } else {
     return cap->capabilities & V4L2_CAP_VIDEO_CAPTURE;
   }
+#else
+    return cap->capabilities & V4L2_CAP_VIDEO_CAPTURE;
+#endif
 }
 
 int32_t DeviceInfoV4l2::FillCapabilities(int fd) {
