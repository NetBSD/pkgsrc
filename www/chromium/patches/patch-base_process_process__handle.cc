$NetBSD: patch-base_process_process__handle.cc,v 1.25 2026/09/02 13:13:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/process_handle.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ base/process/process_handle.cc
@@ -30,7 +30,7 @@ UniqueProcId GetUniqueIdForProcess() {
              : UniqueProcId(GetCurrentProcId());
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
 
 void InitUniqueIdForProcessInPidNamespace(ProcessId pid_outside_of_namespace) {
   DCHECK(pid_outside_of_namespace != kNullProcessId);
