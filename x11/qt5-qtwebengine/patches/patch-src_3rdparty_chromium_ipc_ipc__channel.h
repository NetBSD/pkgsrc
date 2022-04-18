$NetBSD: patch-src_3rdparty_chromium_ipc_ipc__channel.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ipc/ipc_channel.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ipc/ipc_channel.h
@@ -245,7 +245,7 @@ class COMPONENT_EXPORT(IPC) Channel : pu
   static std::string GenerateUniqueRandomChannelID();
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
