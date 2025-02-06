$NetBSD: patch-remoting_host_it2me_it2me__host.cc,v 1.1 2025/02/06 09:58:18 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/it2me/it2me_host.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ remoting/host/it2me/it2me_host.cc
@@ -58,7 +58,7 @@
 #include "remoting/host/chromeos/features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/wayland_manager.h"
 #include "remoting/host/linux/wayland_utils.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -184,7 +184,7 @@ void It2MeHost::Connect(
 
   OnPolicyUpdate(std::move(policies));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsRunningWayland()) {
     WaylandManager::Get()->Init(host_context_->ui_task_runner());
   }
@@ -318,7 +318,7 @@ void It2MeHost::ConnectOnNetworkThread(
 
   // Set up the desktop environment options.
   DesktopEnvironmentOptions options(DesktopEnvironmentOptions::CreateDefault());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsRunningWayland()) {
     options.desktop_capture_options()->set_prefer_cursor_embedded(true);
   }
