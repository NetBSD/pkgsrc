$NetBSD: patch-src_3rdparty_chromium_ipc_ipc__channel__mojo.cc,v 1.1 2025/12/21 09:38:31 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ipc/ipc_channel_mojo.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/ipc/ipc_channel_mojo.cc
@@ -105,7 +105,7 @@ class ThreadSafeChannelProxy : public mo
 };
 
 base::ProcessId GetSelfPID() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (int global_pid = Channel::GetGlobalPid())
     return global_pid;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
