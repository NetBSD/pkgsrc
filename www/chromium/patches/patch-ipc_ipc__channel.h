$NetBSD: patch-ipc_ipc__channel.h,v 1.11 2025/12/11 09:13:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ipc/ipc_channel.h.orig	2025-11-19 21:40:05.000000000 +0000
+++ ipc/ipc_channel.h
@@ -201,7 +201,7 @@ class COMPONENT_EXPORT(IPC) Channel fina
   // Generates a channel ID that's non-predictable and unique.
   static std::string GenerateUniqueRandomChannelID();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
