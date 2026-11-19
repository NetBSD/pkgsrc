$NetBSD: patch-remoting_host_desktop__session__agent.cc,v 1.3 2026/11/19 19:46:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/desktop_session_agent.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ remoting/host/desktop_session_agent.cc
@@ -661,7 +661,7 @@ void DesktopSessionAgent::OnDesktopEnvir
   // LocalInputMonitorWin filters out an echo of the injected input before it
   // reaches |remote_input_filter_|.
   remote_input_filter_->SetExpectLocalEcho(false);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // LocalMouseInputMonitorX11 filters out XTest-injected input before it
   // reaches `remote_input_filter_`.
   if (!webrtc::DesktopCapturer::IsRunningUnderWayland()) {
