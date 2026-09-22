$NetBSD: patch-remoting_host_ipc__desktop__environment.cc,v 1.8 2026/09/22 13:41:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/ipc_desktop_environment.cc.orig	2026-09-14 22:17:16.000000000 +0000
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
@@ -226,7 +226,7 @@ class IpcDesktopEnvironmentFactory::Core
   // the same email address reconnects, the desktop session will be reused and
   // the desktop process will be requested to send a new desktop pipe.
   // TODO: yuweih - see if it makes sense to enable it on Windows.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool persist_desktop_sessions_ = true;
 #else
   bool persist_desktop_sessions_ = false;
@@ -410,7 +410,7 @@ void IpcDesktopEnvironmentFactory::Core:
                          error_details, error_location);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::Core::OnSessionServicesClientConnected(
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
   OnSessionServicesClientConnected(GetEventsReceivers().current_context(),
@@ -463,7 +463,7 @@ void IpcDesktopEnvironmentFactory::Core:
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::Core::OnSessionServicesClientConnected(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
@@ -588,7 +588,7 @@ void IpcDesktopEnvironmentFactory::OnTer
                                 error_location);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::OnSessionServicesClientConnectedForTesting(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
