$NetBSD: patch-remoting_host_ipc__desktop__environment.h,v 1.11 2026/09/29 07:43:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/ipc_desktop_environment.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ remoting/host/ipc_desktop_environment.h
@@ -175,7 +175,7 @@ class IpcDesktopEnvironmentFactory : pub
                                         ErrorCode error_code,
                                         const std::string& error_details,
                                         const SourceLocation& error_location);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnectedForTesting(
       int terminal_id,
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver);
