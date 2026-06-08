$NetBSD: patch-remoting_host_ipc__desktop__environment.cc,v 1.3 2026/06/08 13:12:44 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/ipc_desktop_environment.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ remoting/host/ipc_desktop_environment.cc
@@ -367,7 +367,7 @@ void IpcDesktopEnvironmentFactory::OnTer
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::OnSessionServicesClientConnected(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
