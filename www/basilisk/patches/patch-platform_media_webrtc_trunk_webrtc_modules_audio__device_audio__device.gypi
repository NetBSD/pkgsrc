$NetBSD: patch-platform_media_webrtc_trunk_webrtc_modules_audio__device_audio__device.gypi,v 1.1 2025/04/25 21:25:03 nia Exp $

Add support for non-linux unixes.

--- platform/media/webrtc/trunk/webrtc/modules/audio_device/audio_device.gypi.orig	2025-04-24 10:36:58.372649812 +0000
+++ platform/media/webrtc/trunk/webrtc/modules/audio_device/audio_device.gypi
@@ -66,7 +66,7 @@
             'sndio',
           ],
         }], # include_sndio_audio==1
-        ['OS=="linux" or include_alsa_audio==1 or include_pulse_audio==1', {
+        ['OS=="linux" or OS=="solaris" or os_bsd==1 or include_alsa_audio==1 or include_pulse_audio==1', {
           'include_dirs': [
             'linux',
           ],
