$NetBSD: patch-remoting_host_ipc__desktop__environment.h,v 1.3 2026/05/10 15:30:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/ipc_desktop_environment.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ remoting/host/ipc_desktop_environment.h
@@ -128,7 +128,7 @@ class IpcDesktopEnvironmentFactory : pub
       int session_id,
       mojo::ScopedMessagePipeHandle desktop_pipe) override;
   void OnTerminalDisconnected(int terminal_id) override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnected(
       int terminal_id,
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver)
@@ -160,7 +160,7 @@ class IpcDesktopEnvironmentFactory : pub
   // the same email address reconnects, the desktop session will be reused and
   // the desktop process will be requested to send a new desktop pipe.
   // TODO: yuweih - see if it makes sense to enable it on Windows.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool persist_desktop_sessions_ = true;
 #else
   bool persist_desktop_sessions_ = false;
