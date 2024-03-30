$NetBSD: patch-third__party_libwebrtc_modules_video__capture_video__capture__factory.cc,v 1.1 2024/03/30 11:48:34 maya Exp $

Restore webcam support on BSDs

--- third_party/libwebrtc/modules/video_capture/video_capture_factory.cc.orig	2024-03-30 04:34:50.675628454 +0000
+++ third_party/libwebrtc/modules/video_capture/video_capture_factory.cc
@@ -24,7 +24,7 @@ rtc::scoped_refptr<VideoCaptureModule> V
     const char* deviceUniqueIdUTF8) {
 // This is only implemented on pure Linux and WEBRTC_LINUX is defined for
 // Android as well
-#if !defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
+#if !(defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)) || defined(WEBRTC_ANDROID)
   return nullptr;
 #else
   return videocapturemodule::VideoCaptureImpl::Create(options,
@@ -40,7 +40,7 @@ VideoCaptureModule::DeviceInfo* VideoCap
     VideoCaptureOptions* options) {
 // This is only implemented on pure Linux and WEBRTC_LINUX is defined for
 // Android as well
-#if !defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
+#if !(defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)) || defined(WEBRTC_ANDROID)
   return nullptr;
 #else
   return videocapturemodule::VideoCaptureImpl::CreateDeviceInfo(options);
