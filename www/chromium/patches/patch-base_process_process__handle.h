$NetBSD: patch-base_process_process__handle.h,v 1.11 2025/12/11 09:13:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/process_handle.h.orig	2025-11-19 21:40:05.000000000 +0000
+++ base/process/process_handle.h
@@ -86,7 +86,7 @@ BASE_EXPORT ProcessId GetCurrentProcId()
 // processes may be reused.
 BASE_EXPORT UniqueProcId GetUniqueIdForProcess();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // When a process is started in a different PID namespace from the browser
 // process, this function must be called with the process's PID in the browser's
 // PID namespace in order to initialize its unique ID. Not thread safe.
