$NetBSD: patch-remoting_host_ipc__desktop__environment.cc,v 1.4 2026/07/06 13:06:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/ipc_desktop_environment.cc.orig	2026-06-23 23:37:18.000000000 +0000
+++ remoting/host/ipc_desktop_environment.cc
@@ -371,7 +371,7 @@ void IpcDesktopEnvironmentFactory::OnTer
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::OnSessionServicesClientConnected(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
