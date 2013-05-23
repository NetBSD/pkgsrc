$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_audio__device_audio__device__utility.cc,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/audio_device/audio_device_utility.cc.orig	2013-05-03 03:08:07.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/audio_device/audio_device_utility.cc
@@ -46,7 +46,7 @@ bool AudioDeviceUtility::StringCompare(
 
 }  // namespace webrtc
 
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 
 // ============================================================================
 //                                 Linux & Mac
@@ -109,6 +109,6 @@ bool AudioDeviceUtility::StringCompare(
 
 }  // namespace webrtc
 
-#endif  // defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#endif  // defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 
 
