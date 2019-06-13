$NetBSD: patch-media_webrtc_trunk_webrtc_modules_audio__device_audio__device.gypi,v 1.1 2019/06/13 19:02:37 rjs Exp $

--- media/webrtc/trunk/webrtc/modules/audio_device/audio_device.gypi.orig	2017-10-02 22:22:28.086479246 +0000
+++ media/webrtc/trunk/webrtc/modules/audio_device/audio_device.gypi
@@ -66,7 +66,7 @@
             'sndio',
           ],
         }], # include_sndio_audio==1
-        ['OS=="linux" or include_alsa_audio==1 or include_pulse_audio==1', {
+        ['OS=="linux" or OS=="netbsd" or include_alsa_audio==1 or include_pulse_audio==1', {
           'include_dirs': [
             'linux',
           ],
