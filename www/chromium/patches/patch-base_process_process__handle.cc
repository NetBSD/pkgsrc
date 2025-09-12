$NetBSD: patch-base_process_process__handle.cc,v 1.7 2025/09/12 16:02:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/process_handle.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ base/process/process_handle.cc
@@ -30,7 +30,7 @@ UniqueProcId GetUniqueIdForProcess() {
              : UniqueProcId(GetCurrentProcId());
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
 
 void InitUniqueIdForProcessInPidNamespace(ProcessId pid_outside_of_namespace) {
   DCHECK(pid_outside_of_namespace != kNullProcessId);
