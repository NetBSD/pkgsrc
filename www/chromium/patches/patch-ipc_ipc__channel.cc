$NetBSD: patch-ipc_ipc__channel.cc,v 1.1 2025/11/04 14:55:42 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ipc/ipc_channel.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ ipc/ipc_channel.cc
@@ -22,7 +22,7 @@ namespace {
 // Global atomic used to guarantee channel IDs are unique.
 base::AtomicSequenceNumber g_last_id;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 int g_global_pid = 0;
 
@@ -60,7 +60,7 @@ std::string Channel::GenerateUniqueRando
       base::RandInt(0, std::numeric_limits<int32_t>::max()));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 void Channel::SetGlobalPid(int pid) {
   g_global_pid = pid;
