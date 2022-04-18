$NetBSD: patch-src_3rdparty_chromium_base_process_process__handle.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/process/process_handle.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/process/process_handle.h
@@ -103,7 +103,7 @@ BASE_EXPORT ProcessId GetCurrentProcId()
 // processes may be reused.
 BASE_EXPORT UniqueProcId GetUniqueIdForProcess();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // When a process is started in a different PID namespace from the browser
 // process, this function must be called with the process's PID in the browser's
 // PID namespace in order to initialize its unique ID. Not thread safe.
