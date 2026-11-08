$NetBSD: patch-third__party_blink_renderer_modules_webaudio_audio__worklet__thread__test.cc,v 1.32 2026/11/08 15:39:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc
@@ -464,7 +464,7 @@ class AudioWorkletThreadPriorityTest
     // acquire SCHED_RR, so the thread remains in SCHED_NORMAL. However,
     // ChromeOS applies specific optimizations (Nice -10 and uclamp boost)
     // that are not present on standard Linux.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (expected_priority == base::ThreadType::kRealtimeAudio ||
         expected_priority == base::ThreadType::kPresentation) {
       EXPECT_EQ(actual_priority, base::ThreadType::kDefault);
