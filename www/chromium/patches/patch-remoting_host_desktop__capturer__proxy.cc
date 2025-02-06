$NetBSD: patch-remoting_host_desktop__capturer__proxy.cc,v 1.1 2025/02/06 09:58:17 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/desktop_capturer_proxy.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ remoting/host/desktop_capturer_proxy.cc
@@ -26,7 +26,7 @@
 #include "remoting/host/chromeos/frame_sink_desktop_capturer.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #include "remoting/host/linux/wayland_desktop_capturer.h"
@@ -91,7 +91,7 @@ void DesktopCapturerProxy::Core::CreateC
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   capturer_ = std::make_unique<FrameSinkDesktopCapturer>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static base::nix::SessionType session_type = base::nix::SessionType::kUnset;
   if (session_type == base::nix::SessionType::kUnset) {
     std::unique_ptr<base::Environment> env = base::Environment::Create();
@@ -298,7 +298,7 @@ void DesktopCapturerProxy::OnMetadata(we
 bool DesktopCapturerProxy::SupportsFrameCallbacks() {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return IsRunningWayland();
 #else
   return false;
