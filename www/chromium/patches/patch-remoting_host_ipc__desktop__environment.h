$NetBSD: patch-remoting_host_ipc__desktop__environment.h,v 1.17 2026/11/19 19:46:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/ipc_desktop_environment.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ remoting/host/ipc_desktop_environment.h
@@ -174,7 +174,7 @@ class IpcDesktopEnvironmentFactory : pub
                                         ErrorCode error_code,
                                         const std::string& error_details,
                                         const SourceLocation& error_location);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnectedForTesting(
       int terminal_id,
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver);
