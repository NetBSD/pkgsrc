$NetBSD: patch-src_3rdparty_chromium_media_audio_audio__input__device.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/media/audio/audio_input_device.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/media/audio/audio_input_device.cc
@@ -248,7 +248,7 @@ void AudioInputDevice::OnStreamCreated(
 // also a risk of false positives if we are suspending when starting the stream
 // here. See comments in AliveChecker and PowerObserverHelper for details and
 // todos.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const bool stop_at_first_alive_notification = true;
   const bool pause_check_during_suspend = false;
 #else
