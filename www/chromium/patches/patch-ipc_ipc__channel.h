$NetBSD: patch-ipc_ipc__channel.h,v 1.6 2025/09/08 13:24:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ipc/ipc_channel.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ ipc/ipc_channel.h
@@ -199,7 +199,7 @@ class COMPONENT_EXPORT(IPC) Channel : pu
   // Generates a channel ID that's non-predictable and unique.
   static std::string GenerateUniqueRandomChannelID();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
