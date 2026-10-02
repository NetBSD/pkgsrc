$NetBSD: patch-ipc_ipc__channel.h,v 1.28 2026/10/02 11:43:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ipc/ipc_channel.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ ipc/ipc_channel.h
@@ -165,7 +165,7 @@ class COMPONENT_EXPORT(IPC) Channel fina
   void OnAssociatedInterfaceRequest(
       mojo::GenericPendingAssociatedReceiver receiver) override;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
