$NetBSD: patch-remoting_host_ipc__desktop__environment.cc,v 1.10 2026/10/02 11:43:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/ipc_desktop_environment.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ remoting/host/ipc_desktop_environment.cc
@@ -180,7 +180,7 @@ class IpcDesktopEnvironmentFactory::Core
                               ErrorCode error_code,
                               const std::string& error_details,
                               const SourceLocation& error_location);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnected(
       int terminal_id,
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver);
@@ -192,7 +192,7 @@ class IpcDesktopEnvironmentFactory::Core
   void OnTerminalDisconnected(ErrorCode error_code,
                               const std::string& error_details,
                               const SourceLocation& error_location) override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnected(
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver)
       override;
@@ -351,7 +351,7 @@ void IpcDesktopEnvironmentFactory::Core:
                          error_details, error_location);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::Core::OnSessionServicesClientConnected(
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
   OnSessionServicesClientConnected(GetEventsReceivers().current_context(),
@@ -397,7 +397,7 @@ void IpcDesktopEnvironmentFactory::Core:
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::Core::OnSessionServicesClientConnected(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
@@ -511,7 +511,7 @@ void IpcDesktopEnvironmentFactory::OnTer
                                 error_location);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::OnSessionServicesClientConnectedForTesting(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
