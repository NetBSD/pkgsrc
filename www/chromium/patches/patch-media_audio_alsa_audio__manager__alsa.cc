$NetBSD: patch-media_audio_alsa_audio__manager__alsa.cc,v 1.18 2026/04/21 15:21:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/audio/alsa/audio_manager_alsa.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ media/audio/alsa/audio_manager_alsa.cc
@@ -102,7 +102,9 @@ void AudioManagerAlsa::GetAlsaAudioDevic
   int card = -1;
 
   // Loop through the physical sound cards to get ALSA device hints.
+#if !BUILDFLAG(IS_BSD) 
   while (!wrapper_->CardNext(&card) && card >= 0) {
+#endif
     void** hints = nullptr;
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
@@ -114,7 +116,9 @@ void AudioManagerAlsa::GetAlsaAudioDevic
       DLOG(WARNING) << "GetAlsaAudioDevices: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#if !BUILDFLAG(IS_BSD) 
   }
+#endif
 }
 
 void AudioManagerAlsa::GetAlsaDevicesInfo(AudioManagerAlsa::StreamType type,
@@ -198,7 +202,11 @@ bool AudioManagerAlsa::IsAlsaDeviceAvail
   // goes through software conversion if needed (e.g. incompatible
   // sample rate).
   // TODO(joi): Should we prefer "hw" instead?
+#if BUILDFLAG(IS_BSD)
+  static constexpr std::string_view kDeviceTypeDesired = "plug";
+#else
   static constexpr std::string_view kDeviceTypeDesired = "plughw";
+#endif
   return device_name.starts_with(kDeviceTypeDesired);
 }
 
@@ -249,7 +257,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDe
   // Loop through the sound cards.
   // Don't use snd_device_name_hint(-1,..) since there is an access violation
   // inside this ALSA API with libasound.so.2.0.0.
+#if !BUILDFLAG(IS_BSD)
   while (!wrapper_->CardNext(&card) && (card >= 0) && !has_device) {
+#endif
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
       const std::string_view unwanted_type =
@@ -278,7 +288,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDe
       DLOG(WARNING) << "HasAnyAudioDevice: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#if !BUILDFLAG(IS_BSD)
   }
+#endif
 
   return has_device;
 }
