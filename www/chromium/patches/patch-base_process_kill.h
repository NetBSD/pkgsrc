$NetBSD: patch-base_process_kill.h,v 1.25 2026/09/02 13:13:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/kill.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ base/process/kill.h
@@ -125,7 +125,7 @@ BASE_EXPORT TerminationStatus GetTermina
 BASE_EXPORT TerminationStatus
 GetKnownDeadTerminationStatus(ProcessHandle handle, int* exit_code);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Spawns a thread to wait asynchronously for the child |process| to exit
 // and then reaps it.
 BASE_EXPORT void EnsureProcessGetsReaped(Process process);
