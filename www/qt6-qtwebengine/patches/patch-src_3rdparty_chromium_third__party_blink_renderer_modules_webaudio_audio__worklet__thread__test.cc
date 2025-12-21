$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_modules_webaudio_audio__worklet__thread__test.cc,v 1.1 2025/12/21 09:38:40 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc
@@ -469,7 +469,7 @@ class AudioWorkletThreadPriorityTest
 
     // TODO(crbug.com/1022888): The worklet thread priority is always NORMAL
     // on OS_LINUX and OS_CHROMEOS regardless of the thread priority setting.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (expected_priority == base::ThreadPriorityForTest::kRealtimeAudio ||
         expected_priority == base::ThreadPriorityForTest::kDisplay) {
       EXPECT_EQ(actual_priority, base::ThreadPriorityForTest::kNormal);
