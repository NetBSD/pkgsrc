$NetBSD: patch-base_process_kill.h,v 1.6 2025/09/08 13:24:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/kill.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ base/process/kill.h
@@ -123,7 +123,7 @@ BASE_EXPORT TerminationStatus GetTermina
 BASE_EXPORT TerminationStatus
 GetKnownDeadTerminationStatus(ProcessHandle handle, int* exit_code);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Spawns a thread to wait asynchronously for the child |process| to exit
 // and then reaps it.
 BASE_EXPORT void EnsureProcessGetsReaped(Process process);
