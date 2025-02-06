$NetBSD: patch-media_audio_audio__input__device.cc,v 1.1 2025/02/06 09:58:11 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/audio/audio_input_device.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/audio/audio_input_device.cc
@@ -269,7 +269,7 @@ void AudioInputDevice::OnStreamCreated(
 // here. See comments in AliveChecker and PowerObserverHelper for details and
 // todos.
   if (detect_dead_stream_ == DeadStreamDetection::kEnabled) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     const bool stop_at_first_alive_notification = true;
     const bool pause_check_during_suspend = false;
 #else
