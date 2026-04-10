$NetBSD: patch-remoting_host_it2me_it2me__host.cc,v 1.5 2026/04/10 17:31:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/it2me/it2me_host.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ remoting/host/it2me/it2me_host.cc
@@ -73,7 +73,7 @@
 #include "remoting/host/chromeos/features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/gnome_remote_desktop_session.h"
 #include "remoting/host/linux/portal_remote_desktop_session.h"
 #endif
@@ -284,7 +284,7 @@ void It2MeHost::ConnectOnNetworkThread(
 
   SetState(It2MeHostState::kStarting, ErrorCode::OK);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!GnomeRemoteDesktopSession::IsRunningUnderGnome()) {
     PortalRemoteDesktopSession::GetInstance()->SetCreateVirtualMonitor(false);
   }
