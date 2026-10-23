$NetBSD: patch-remoting_host_desktop__process.cc,v 1.1 2026/10/23 15:05:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/desktop_process.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ remoting/host/desktop_process.cc
@@ -32,7 +32,7 @@
 #include "base/win/windows_version.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/pulse_audio_capturer.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -120,7 +120,7 @@ void DesktopProcess::OnChannelError() {
   desktop_session_request_handler_.reset();
   worker_process_control_.reset();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Cause the global AudioPipeReader to be freed, otherwise the audio thread
   // will remain in-use and prevent the process from exiting.
   PulseAudioCapturer::InitializePipeReader(nullptr);
@@ -184,7 +184,7 @@ bool DesktopProcess::Start(
       "ChromotingAudioThread", caller_task_runner_, base::MessagePumpType::IO);
 #endif  // !BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Wayland sessions do not set `CHROME_REMOTE_DESKTOP_AUDIO_PIPE`, in which
   // case this will fail and `PipewireAudioCapturer` will be used instead.
   PulseAudioCapturer::InitializePipeReader(audio_task_runner_);
