$NetBSD: patch-third__party_libwebrtc_modules_audio__device_audio__device__impl.cc,v 1.4 2025/10/27 14:24:33 ryoon Exp $

--- third_party/libwebrtc/modules/audio_device/audio_device_impl.cc.orig	2025-10-03 13:18:12.000000000 +0000
+++ third_party/libwebrtc/modules/audio_device/audio_device_impl.cc
@@ -33,7 +33,7 @@
 #if defined(WEBRTC_WINDOWS_CORE_AUDIO_BUILD)
 #include "modules/audio_device/win/audio_device_core_win.h"
 #endif
-#elif defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 #if defined(WEBRTC_ENABLE_LINUX_ALSA)
 #include "modules/audio_device/linux/audio_device_alsa_linux.h"
 #endif
@@ -151,6 +151,11 @@ int32_t AudioDeviceModuleImpl::CheckPlat
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
@@ -204,7 +209,7 @@ int32_t AudioDeviceModuleImpl::CreatePla
 // 'rtc_include_pulse_audio' build flag.
 // TODO(bugs.webrtc.org/9127): improve support and make it more clear that
 // PulseAudio is the default selection.
-#if !defined(WEBRTC_ANDROID) && defined(WEBRTC_LINUX)
+#if !defined(WEBRTC_ANDROID) && (defined(WEBRTC_LINUX) || defined(WEBRTC_BSD))
 #if !defined(WEBRTC_ENABLE_LINUX_PULSE)
   // Build flag 'rtc_include_pulse_audio' is set to false. In this mode:
   // - kPlatformDefaultAudio => ALSA, and
