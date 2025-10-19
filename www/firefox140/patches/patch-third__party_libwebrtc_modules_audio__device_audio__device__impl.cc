$NetBSD: patch-third__party_libwebrtc_modules_audio__device_audio__device__impl.cc,v 1.1 2025/10/19 11:56:57 leot Exp $

--- third_party/libwebrtc/modules/audio_device/audio_device_impl.cc.orig	2025-05-21 12:45:39.616635762 +0000
+++ third_party/libwebrtc/modules/audio_device/audio_device_impl.cc
@@ -28,7 +28,7 @@
 #include <stdlib.h>
 
 #include "sdk/android/native_api/audio_device_module/audio_device_android.h"
-#elif defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 #if defined(WEBRTC_ENABLE_LINUX_ALSA)
 #include "modules/audio_device/linux/audio_device_alsa_linux.h"
 #endif
@@ -155,6 +155,11 @@ int32_t AudioDeviceModuleImpl::CheckPlat
 #elif defined(WEBRTC_FUCHSIA)
   platform = kPlatformFuchsia;
   RTC_LOG(LS_INFO) << "current platform is Fuchsia";
+#elif defined(WEBRTC_BSD)
+#  if defined(__NetBSD__)
+  platform = kPlatformNetBSD;
+  RTC_LOG(LS_INFO) << "current platform is NetBSD";
+#  endif
 #endif
   if (platform == kPlatformNotSupported) {
     RTC_LOG(LS_ERROR)
@@ -207,7 +212,7 @@ int32_t AudioDeviceModuleImpl::CreatePla
 // 'rtc_include_pulse_audio' build flag.
 // TODO(bugs.webrtc.org/9127): improve support and make it more clear that
 // PulseAudio is the default selection.
-#if !defined(WEBRTC_ANDROID) && defined(WEBRTC_LINUX)
+#if !defined(WEBRTC_ANDROID) && (defined(WEBRTC_LINUX) || defined(WEBRTC_BSD))
 #if !defined(WEBRTC_ENABLE_LINUX_PULSE)
   // Build flag 'rtc_include_pulse_audio' is set to false. In this mode:
   // - kPlatformDefaultAudio => ALSA, and
