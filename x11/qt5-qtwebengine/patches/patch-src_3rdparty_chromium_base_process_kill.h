$NetBSD: patch-src_3rdparty_chromium_base_process_kill.h,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/process/kill.h.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/process/kill.h
@@ -118,7 +118,7 @@ BASE_EXPORT TerminationStatus GetTermina
 BASE_EXPORT TerminationStatus GetKnownDeadTerminationStatus(
     ProcessHandle handle, int* exit_code);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Spawns a thread to wait asynchronously for the child |process| to exit
 // and then reaps it.
 BASE_EXPORT void EnsureProcessGetsReaped(Process process);
