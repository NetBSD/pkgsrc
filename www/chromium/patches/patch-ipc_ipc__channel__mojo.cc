$NetBSD: patch-ipc_ipc__channel__mojo.cc,v 1.10 2025/11/20 08:36:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ipc/ipc_channel_mojo.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ ipc/ipc_channel_mojo.cc
@@ -72,7 +72,7 @@ class ThreadSafeChannelProxy : public mo
 };
 
 base::ProcessId GetSelfPID() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (int global_pid = Channel::GetGlobalPid())
     return global_pid;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
