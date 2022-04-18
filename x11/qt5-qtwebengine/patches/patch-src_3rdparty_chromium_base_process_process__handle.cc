$NetBSD: patch-src_3rdparty_chromium_base_process_process__handle.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/process/process_handle.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/process/process_handle.cc
@@ -30,7 +30,7 @@ UniqueProcId GetUniqueIdForProcess() {
              : UniqueProcId(GetCurrentProcId());
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX) || defined(OS_BSD)
 
 void InitUniqueIdForProcessInPidNamespace(ProcessId pid_outside_of_namespace) {
   DCHECK(pid_outside_of_namespace != kNullProcessId);
