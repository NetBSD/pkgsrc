$NetBSD: patch-remoting_host_ipc__desktop__environment.h,v 1.14 2026/10/16 15:30:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/ipc_desktop_environment.h.orig	2026-10-14 21:09:54.000000000 +0000
+++ remoting/host/ipc_desktop_environment.h
@@ -173,7 +173,7 @@ class IpcDesktopEnvironmentFactory : pub
                                         ErrorCode error_code,
                                         const std::string& error_details,
                                         const SourceLocation& error_location);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnectedForTesting(
       int terminal_id,
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver);
