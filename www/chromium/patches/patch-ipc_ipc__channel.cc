$NetBSD: patch-ipc_ipc__channel.cc,v 1.6 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ipc/ipc_channel.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ipc/ipc_channel.cc
@@ -41,7 +41,7 @@ namespace {
 // Global atomic used to guarantee channel IDs are unique.
 base::AtomicSequenceNumber g_last_id;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 int g_global_pid = 0;
 
@@ -83,7 +83,7 @@ class ThreadSafeChannelProxy : public mo
 };
 
 base::ProcessId GetSelfPID() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (int global_pid = Channel::GetGlobalPid()) {
     return global_pid;
   }
@@ -120,7 +120,7 @@ std::string Channel::GenerateUniqueRando
       base::RandInt(0, std::numeric_limits<int32_t>::max()));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 void Channel::SetGlobalPid(int pid) {
   g_global_pid = pid;
