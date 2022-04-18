$NetBSD: patch-src_3rdparty_chromium_ipc_ipc__channel__mojo.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ipc/ipc_channel_mojo.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ipc/ipc_channel_mojo.cc
@@ -74,7 +74,7 @@ class MojoChannelFactory : public Channe
 };
 
 base::ProcessId GetSelfPID() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (int global_pid = Channel::GetGlobalPid())
     return global_pid;
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
