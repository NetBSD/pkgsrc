$NetBSD: patch-remoting_host_mouse__cursor__monitor__proxy.cc,v 1.1 2025/02/06 09:58:18 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/mouse_cursor_monitor_proxy.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ remoting/host/mouse_cursor_monitor_proxy.cc
@@ -73,7 +73,7 @@ void MouseCursorMonitorProxy::Core::Crea
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   mouse_cursor_monitor_ = std::make_unique<MouseCursorMonitorAura>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsRunningWayland()) {
     mouse_cursor_monitor_ = webrtc::MouseCursorMonitor::Create(options);
   } else {
