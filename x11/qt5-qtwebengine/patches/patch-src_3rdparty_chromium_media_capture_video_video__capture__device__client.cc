$NetBSD: patch-src_3rdparty_chromium_media_capture_video_video__capture__device__client.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/media/capture/video/video_capture_device_client.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/video_capture_device_client.cc
@@ -318,7 +318,7 @@ void VideoCaptureDeviceClient::OnIncomin
 // see http://linuxtv.org/downloads/v4l-dvb-apis/packed-rgb.html.
 // Windows RGB24 defines blue at lowest byte,
 // see https://msdn.microsoft.com/en-us/library/windows/desktop/dd407253
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       fourcc_format = libyuv::FOURCC_RAW;
 #elif defined(OS_WIN)
       fourcc_format = libyuv::FOURCC_24BG;
