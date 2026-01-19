$NetBSD: patch-third__party_blink_renderer_modules_webaudio_audio__worklet__thread__test.cc,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc
@@ -463,7 +463,7 @@ class AudioWorkletThreadPriorityTest
 
     // TODO(crbug.com/1022888): The worklet thread priority is always NORMAL
     // on OS_LINUX and OS_CHROMEOS regardless of the thread priority setting.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (expected_priority == base::ThreadType::kRealtimeAudio ||
         expected_priority == base::ThreadType::kDisplayCritical) {
       EXPECT_EQ(actual_priority, base::ThreadType::kDefault);
